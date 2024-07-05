#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include "Indexer.h"
using namespace std;

class Interface {
public:
    Interface(Indexer& idx) : indexer(idx) {}

    void run() {
        string rootPath = "C:\\Uni\\";
        string query;
        cout << "Enter query: ";
        getline(cin, query);
        indexer.indexAllTextFiles(rootPath);
        auto sortedFiles = indexer.sortFilesByWordFrequency(query);
        cout << "Files sorted by frequency of the word or query '" << query << "':\n";
        for (const auto& pair : sortedFiles) {
            cout << pair.first << " (" << pair.second << ")\n";
        }
    }

private:
    Indexer& indexer;
};

#endif
