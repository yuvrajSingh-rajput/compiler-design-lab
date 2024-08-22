#include<bits/stdc++.h>
using namespace std;

void countComments(string& filePath, int &singleLine, int& multiLine){
    ifstream sourceFile(filePath);
    bool inMultilineComment = false;
    if(!sourceFile.is_open()){
        cerr << "Error in opening the file: " << filePath << endl;
        return;
    }

    string line;
    while(getline(sourceFile, line)){
        if(!inMultilineComment){
            if(line.find("//") != string:: npos){
                singleLine++;
                continue;
            }
        }

        if(line.find("/*") != string:: npos || inMultilineComment){
            inMultilineComment = true;
            multiLine++;
        }

        if(inMultilineComment){
            if(line.find("*/") != string:: npos){
                inMultilineComment = false;

                if(line.find("//") != string:: npos){
                    singleLine++;
                    continue;
                }
            }
        }
    }

    sourceFile.close();
}

void writeWithoutComments(string& filePath, string& destFilePath){
    ifstream sourceFile(filePath);
    ofstream destinationFile(destFilePath);

    if(!sourceFile.is_open()){
        cerr << "Error in opening file " << filePath << endl;
        return;
    }

    if(!destinationFile.is_open()){
        cerr << "Error in opening file " << destFilePath << endl;
        return;
    }
    bool inMultiline = false;

    string line;
    while(getline(sourceFile, line)){
        if(!inMultiline){
            int pos = line.find("//");
            if(pos != string:: npos){
                if(pos != 0){
                    destinationFile << line.substr(0, pos);
                }
                destinationFile << endl;
                continue;
            }
        }

        if(line.find("/*") != string:: npos){
            inMultiline = true;
        }else if(inMultiline){
            int pos1 = line.find("*/");
            if(pos1 != string :: npos){
                inMultiline = false;

                int pos2 = line.substr(pos1 + 2).find("//");
                if(pos2 != string:: npos){
                    destinationFile << line.substr(pos1 + 2, pos2);
                }else{
                    destinationFile << line.substr(pos1 + 2);
                }
                destinationFile << endl;
            }
        }else {
            destinationFile << line << endl;
        }
    }

    sourceFile.close();
    destinationFile.close();
}

signed main(int argc, char* argv[]){
    int singleLine = 0, multiLine = 0;
    string filePath = "C_code.c", destFilePath = "withoutCommentC_program.c";

    countComments(filePath, singleLine, multiLine);
    cout << "Number of Comment Lines in the given C program = " << singleLine + multiLine << endl;

    writeWithoutComments(filePath, destFilePath);
    
    return 0;
}
