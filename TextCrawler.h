#ifndef TEXTCRAWLER_H
#define TEXTCRAWLER_H

#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class TextCrawler {
public:
    string extractText(const string& filePath) {
        ifstream file(filePath);
        stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }
};

#endif
