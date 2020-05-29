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

string inputText()
{
    ofstream write;
    string inputFile = "input.txt";
    write.open(inputFile);
    string text;

    getline(cin, text);
    write << text;

    write.close();

    return text;
}

void clearText(string readFile, string writeFile)
{
    ifstream read;
    ofstream write;
    read.open(readFile);
    write.open(writeFile);
    const unsigned int notFounded = 4294967295;

    string word;
    while (read >> word) {
        string symb = ".()-:!?[]*%;#№@$&+=_";
        while (word.rfind(",") != notFounded
               && word.rfind(",") == word.length() - 1) {
            word = word.erase(word.rfind(","), 1);
        }
        for (int i = 0; i < 22; i++) {
            while (word.rfind(symb[i]) != notFounded
                   && (word.rfind(symb[i]) == word.length() - 1
                       || word.rfind(symb[i]) == word.length() - word.size())) {
                word = word.erase(word.rfind(symb[i]), 1);
            }
        }

        write << word << " ";
    }
    cout << endl << endl;
    write.close();
}
