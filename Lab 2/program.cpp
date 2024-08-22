#include<bits/stdc++.h>
using namespace std;

void searchCountAndReplaceWord(string& filepath, string& oldWord, string& replaceWord, int &count){
    ifstream inputFile(filepath);
    
    if(!inputFile.is_open()){
        cerr << "Error in opening input.txt file!";
        return;
    }
    ofstream tempFile("temp.txt");
    if(!tempFile.is_open()){
        cerr << "Error in opening temp.txt file!";
        return;
    }
    string s;
    while(getline(inputFile, s)){
        while(s.find(oldWord) != string::npos){
            int idx = s.find(oldWord);
            s.erase(idx, oldWord.length());
            s.insert(idx, replaceWord);
            count++;
        }
        tempFile << s << endl;
    }
    tempFile.close();
    inputFile.close();

    ifstream tmpFile("temp.txt");
    if(!tmpFile.is_open()){
        cerr << "Error in opening temp.txt file!";
        return;
    }
    
    ofstream ipFile(filepath);
    if(!ipFile.is_open()){
        cerr << "Error in opening input.txt file!";
        return;
    }
    while(getline(tmpFile, s)){
        ipFile << s << endl;
    }
    ipFile.close();
    tmpFile.close();
}

int main(int argc, char* argv[]){
    string oldWord = "grocery", newWord = "medical", filepath = "input.txt";
    int count = 0;

    ofstream writeInFile(filepath);
    if(!writeInFile.is_open()){
        cerr << "Error in opening input.txt!";
        return 1;
    }

    writeInFile << "He raced to the grocery store. He went inside but realized he forgot his wallet. He raced back home to grab it. Once he found it, he raced to the car again and drove back to the grocery store.\n";
    writeInFile.close();

    searchCountAndReplaceWord(filepath, oldWord, newWord, count);
    cout << count << endl;
}
