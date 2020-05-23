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

string missingLetter(string word, unordered_set<string> Dictionary)
{
    int flag = 0;
    string alfavit = "abcdefghijklmnopqrstuvwxyz";
    string result;
    string newWord = "_" + word;
    int wordSize = newWord.size();
    for (int i = 0; i < wordSize; i++) {
        for (int j = 0; j < 27; j++) {
            newWord[i] = alfavit[j];
            if (Dictionary.find(newWord) != Dictionary.end()) {
                result = newWord;
                flag = 1;
            }
        }
        if (flag) {
            break;
        } else {
            swap(newWord[i], newWord[i + 1]);
        }
    }
    return result;
}

string swapLetters(string word, unordered_set<string> Dictionary)
{
    int wordSize = word.size();
    string result;
    for (int i = 0; i < wordSize; i++) {
        string newWord = word;
        swap(newWord[i], newWord[i + 1]);
        if (Dictionary.find(newWord) != Dictionary.end()) {
            result = newWord;
        }
    }
    return result;
}

string wrongLetter(string word, unordered_set<string> Dictionary)
{
    bool wordFinded = false;
    string alfavit = "abcdefghijklmnopqrstuvwxyz";
    string result;
    string bufWord = word;
    int wordSize = word.size();
    for (int i = 0; i < wordSize; i++) {
        word = bufWord;
        for (int j = 0; j < 27; j++) {
            word[i] = alfavit[j];
            if (Dictionary.find(word) != Dictionary.end()) {
                result = word;
                wordFinded = true;
            }
        }
        if (wordFinded) {
            break;
        }
    }
    return result;
}

void checkText(string filename, unordered_set<string> Dictionary)
{
    ifstream read;
    read.open(filename);
    if (read.is_open()) {
        string word;
        while (read >> word) {
            lowerCase(word);
            cout << word;
            if (Dictionary.find(word) != Dictionary.end()) {
                cout << " -> correct word" << endl;
            } else {
                string wordContainer = swapLetters(word, Dictionary);
                if (wordContainer.empty()) {
                    wordContainer = excessLetter(word, Dictionary);
                    if (wordContainer.empty()) {
                        wordContainer = missingLetter(word, Dictionary);
                        if (wordContainer.empty()) {
                            cout << " -> unknown or nonexistent word" << endl;
                        } else {
                            cout << " -> uncorrect word, maybe you mean -->> "
                                 << wordContainer << endl;
                        }
                    } else {
                        cout << " -> uncorrect word, maybe you mean -->> "
                             << wordContainer << endl;
                    }
                } else {
                    cout << " -> uncorrect word, maybe you mean -->> "
                         << wordContainer << endl;
                }
            }
        }
    } else {
        cout << "Could not open file: " << filename << endl;
    }
}
