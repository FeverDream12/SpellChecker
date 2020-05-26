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

string excessLetter(string word, unordered_set<string> Dictionary, string& text)
{
    int wordSize = word.size();
    string result;
    for (int i = 0; i < wordSize; i++) {
        string newWord = word;
        newWord = newWord.erase(i, 1);
        if (Dictionary.find(newWord) != Dictionary.end()) {
            result = newWord;
            int fPos = text.find(word);
            text.replace(
                    text.begin() + fPos,
                    text.begin() + fPos + word.size(),
                    result);
            break;
        }
    }
    return result;
}

string
missingLetter(string word, unordered_set<string> Dictionary, string& text)
{
    bool find = false;
    string alfavit = "abcdefghijklmnopqrstuvwxyz";
    string result;
    string newWord = "_" + word;
    int wordSize = newWord.size();
    for (int i = 0; i < wordSize; i++) {
        for (int j = 0; j < 26; j++) {
            newWord[i] = alfavit[j];
            if (Dictionary.find(newWord) != Dictionary.end()) {
                result = newWord;
                int wordPosition = text.find(word);

                text.replace(
                        text.begin() + wordPosition,
                        text.begin() + wordPosition + word.size(),
                        result);
                find = true;
            }
        }
        if (find) {
            break;
        } else {
            swap(newWord[i], newWord[i + 1]);
        }
    }
    return result;
}

string swapLetters(string word, unordered_set<string> Dictionary, string& text)
{
    int wordSize = word.size();
    string result;
    for (int i = 0; i < wordSize; i++) {
        string newWord = word;
        swap(newWord[i], newWord[i + 1]);
        if (Dictionary.find(newWord) != Dictionary.end()) {
            result = newWord;
            int wordPosition = text.find(word);

            text.replace(
                    text.begin() + wordPosition,
                    text.begin() + wordPosition + word.size(),
                    result);
        }
    }
    return result;
}

string wrongLetter(string word, unordered_set<string> Dictionary, string& text)
{
    bool find = false;
    string alfavit = "abcdefghijklmnopqrstuvwxyz";
    string result;
    string newWord = word;
    int wordSize = newWord.size();
    for (int i = 0; i < wordSize; i++) {
        newWord = word;
        for (int j = 0; j < 26; j++) {
            newWord[i] = alfavit[j];
            if (Dictionary.find(newWord) != Dictionary.end()) {
                result = newWord;
                int wordPosition = text.find(word);
                text.replace(
                        text.begin() + wordPosition,
                        text.begin() + wordPosition + word.size(),
                        result);
                find = true;
                break;
            }
        }
        if (find) {
            break;
        }
    }
    return result;
}

string
checkText(string filename, unordered_set<string> Dictionary, string& text)
{
    ifstream read;
    read.open(filename);
    if (read.is_open()) {
        string word;
        while (read >> word) {
            lowerCase(word);
            cout << word;
            if (Dictionary.find(word) != Dictionary.end()) {
                cout << "\033[1;32m -> correct word \033[0m" << endl;
            } else {
                string wordContainer = swapLetters(word, Dictionary, text);
                if (wordContainer.empty()) {
                    wordContainer = excessLetter(word, Dictionary, text);
                    if (wordContainer.empty()) {
                        wordContainer = missingLetter(word, Dictionary, text);
                        if (wordContainer.empty()) {
                            wordContainer = wrongLetter(word, Dictionary, text);
                            if (wordContainer.empty()) {
                                cout << "\033[1;31m -> unknown or nonexisted word \033[0m"
                                     << endl;
                            } else {
                                cout << "\033[1;33m -> uncorrect word, maybe you mean -->> \033[0m"
                                     << wordContainer << endl;
                            }
                        } else {
                            cout << " \033[1;33m -> uncorrect word, maybe you mean -->> \033[0m"
                                 << wordContainer << endl;
                        }
                    } else {
                        cout << " \033[1;33m -> uncorrect word, maybe you mean -->> \033[0m"
                             << wordContainer << endl;
                    }

                } else {
                    cout << " \033[1;33m-> uncorrect word, maybe you mean -->> \033[0m"
                         << wordContainer << endl;
                }
            }
        }
    } else {
        cout << "Could not open file : " << filename << endl;
    }
    return text;
}
