#ifndef INDEXER_H
#define INDEXER_H

#include "LRUCache.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <stdexcept>
#include <cctype>
#include <functional>
#include <filesystem>
#include <list>
using namespace std;

namespace fs = filesystem;

class Indexer {
public:
    Indexer(int cacheSize) : cache(cacheSize) {}

    void indexAllTextFiles(const string& rootPath) {
        for (const auto& entry : fs::recursive_directory_iterator(rootPath)) {
            if (entry.is_regular_file() && entry.path().extension() == ".txt") {
                string filePath = entry.path().string();
                ifstream file(filePath);
                stringstream buffer;
                buffer << file.rdbuf();
                addDocument(filePath, buffer.str());
            }
        }
    }

    vector<pair<string, int>> sortFilesByWordFrequency(const string& query) {
        istringstream iss(query);
        string word;
        vector<string> words;
        bool isAnd = false, isOr = false;

        while (iss >> word) {
            word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
            transform(word.begin(), word.end(), word.begin(), ::tolower);

            if (word == "and") {
                isAnd = true;
            }
            else if (word == "or") {
                isOr = true;
            }
            else {
                words.push_back(word);
            }
        }

        if (isAnd) {
            return sortAnd(words);
        }
        else if (isOr) {
            return sortOr(words);
        }
        else {
            return sortSimple(words);
        }
    }

    void addToSearchHistory(const string& query) {
        string filename = "search_history.txt";

        ifstream infile(filename);
        string history;
        if (infile.is_open()) {
            stringstream ss;
            ss << infile.rdbuf();
            history = ss.str();
        }
        infile.close();

        ofstream outfile(filename);
        if (!outfile.is_open()) {
            return;
        }

        outfile << query << "\r\n" << endl;
        outfile << history;

        outfile.close();
    }

private:
    unordered_map<string, unordered_map<string, int>> index;
    LRUCache<string, vector<string>> cache;

    void addDocument(const string& docID, const string& content) {
        istringstream iss(content);
        string word;
        while (iss >> word) {
            word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            index[docID][word]++;
        }
    }

    vector<pair<string, int>> sortSimple(const vector<string>& words) {
        map<string, int> wordFreq;
        for (const auto& word : words) {
            for (const auto& page : index) {
                if (page.second.find(word) != page.second.end()) {
                    wordFreq[page.first] += page.second.at(word);
                }
            }
        }
        vector<pair<string, int>> sortedFiles(wordFreq.begin(), wordFreq.end());
        sort(sortedFiles.begin(), sortedFiles.end(), [](const auto& a, const auto& b) {
            return b.second < a.second;
            });
        return sortedFiles;
    }

    vector<pair<string, int>> sortAnd(const vector<string>& words) {
        map<string, int> wordFreq;
        for (const auto& page : index) {
            bool allWordsFound = true;
            int totalFreq = 0;
            for (const auto& word : words) {
                if (page.second.find(word) == page.second.end()) {
                    allWordsFound = false;
                    break;
                }
                else {
                    totalFreq += page.second.at(word);
                }
            }
            if (allWordsFound) {
                wordFreq[page.first] = totalFreq;
            }
        }
        vector<pair<string, int>> sortedFiles(wordFreq.begin(), wordFreq.end());
        sort(sortedFiles.begin(), sortedFiles.end(), [](const auto& a, const auto& b) {
            return b.second > a.second;
            });
        return sortedFiles;
    }

    vector<pair<string, int>> sortOr(const vector<string>& words) {
        map<string, int> wordFreq;
        for (const auto& word : words) {
            for (const auto& page : index) {
                if (page.second.find(word) != page.second.end()) {
                    wordFreq[page.first] += page.second.at(word);
                }
            }
        }
        vector<pair<string, int>> sortedFiles(wordFreq.begin(), wordFreq.end());
        sort(sortedFiles.begin(), sortedFiles.end(), [](const auto& a, const auto& b) {
            return b.second < a.second;
            });
        return sortedFiles;
    }

    vector<string> rankResults(const unordered_map<string, int>& relevance) {
        vector<pair<string, int>> rankedPages(relevance.begin(), relevance.end());
        sort(rankedPages.begin(), rankedPages.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
            });
        vector<string> results;
        for (const auto& pair : rankedPages) {
            results.push_back(pair.first);
        }
        return results;
    }
};
#endif