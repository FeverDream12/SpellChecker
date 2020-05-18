#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string lowerCase(string& str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

void inputText()
{
    ofstream write;
    string inputFile = "input.txt";
    write.open(inputFile);
    string text;

    getline(cin, text);
    write << text;

    write.close();
}

void clearText(string readFile, string writeFile)
{
    ifstream read;
    ofstream write;
    read.open(readFile);
    write.open(writeFile);

    string word;
    while (read >> word) {
        string symb = ".()-:!?[]*%;#№@$&+=_";
        while (word.rfind(",") != 4294967295
               && word.rfind(",") == word.length() - 1) {
            word = word.erase(word.rfind(","), 1);
        }
        for (int i = 0; i < 22; i++) {
            while (word.rfind(symb[i]) != 4294967295) {
                word = word.erase(word.rfind(symb[i]), 1);
            }
        }

        write << word << " ";
    }
    cout << endl << endl;
    write.close();
}
