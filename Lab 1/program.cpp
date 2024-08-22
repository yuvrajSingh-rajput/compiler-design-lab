#include <bits/stdc++.h>
using namespace std;

void countCharWordLineAndSpace(const string &filepath, int &spaceCount, int &wordCount, int &charCount, int &lineCount) {
    ifstream inputFile(filepath);

    if (!inputFile.is_open()) {
        cerr << "Error opening " << filepath << " file" << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string word;
        while (iss >> word) {
            wordCount++;
            charCount += word.length();
        }
        charCount += line.length() - charCount; 
        spaceCount += count(line.begin(), line.end(), ' ');
        lineCount++;
    }
    inputFile.close();
}

int main() {
    string filepath = "input1.txt";
    int charCount = 0, wordCount = 0, lineCount = 0, spaceCount = 0;

    ofstream writeFile(filepath);
    if (!writeFile.is_open()) {
        cerr << "Error opening input1.txt file!" << endl;
        return 1;
    }

    writeFile << "Hello world\nThis is a test file.\nC++ programming is fun.";
    writeFile.close();

    countCharWordLineAndSpace(filepath, spaceCount, wordCount, charCount, lineCount);

    cout << "No of characters: " << charCount << endl;
    cout << "No of words: " << wordCount << endl;
    cout << "No of spaces: " << spaceCount << endl;
    cout << "No of lines: " << lineCount << endl;

    return 0;
}
