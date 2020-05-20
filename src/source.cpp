#include "textWork.h"
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

unordered_set<string> introduceDictionary(string filename)
{
    unordered_set<string> Dictionary;
    ifstream dictFile;
    dictFile.open(filename);
    if (dictFile.is_open()) {
        string word;
        while (dictFile >> word) {
            lowerCase(word);
            Dictionary.insert(word);
        }
    } else {
        cout << "Can't open file: " << filename << endl;
    }
    return Dictionary;
}

string excessLetter(string word, unordered_set<string> Dictionary)
{
    string result;
    int wordSize = word.size();
    for (int i = 0; i < wordSize; ++i) {
        string newWord = word;
        newWord = newWord.erase(i, 1);
        if (Dictionary.find(newWord) != Dictionary.end()) {
            result = newWord;
        }
    }
    return result;
}

void checkText(string filename, unordered_set<string> Dictionary)
{
    ifstream readFile;
    readFile.open(filename);
    if (readFile.is_open()) {
        string word;
        while (readFile >> word) {
            lowerCase(word);
            cout << word;
            if (Dictionary.find(word) != Dictionary.end()) {
                cout << " -> correct word" << endl;
            } else {
                string altWordList = excessLetter(word, Dictionary);
                if (altWordList.empty()) {
                    cout << " -> unknown or nonexistent word" << endl;
                } else {
                    cout << " -> uncorrect word, maybe you mean -->> ";
                    cout << altWordList;
                    cout << endl;
                }
            }
        }
    } else {
        cout << "Не удалось открыть файл: " << filename << endl;
    }
}
