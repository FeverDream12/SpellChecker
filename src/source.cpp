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

string excessLetter(
        string word, unordered_set<string> dict, string& text, int findHelper)
{
    int wordSize = word.size();
    string result;
    for (int i = 0; i < wordSize; i++) {
        string newWord = word;
        newWord = newWord.erase(i, 1);
        if (dict.find(newWord) != dict.end()) {
            result = newWord;
            int wordPosition = text.find(word, findHelper);

            text.replace(
                    text.begin() + wordPosition,
                    text.begin() + wordPosition + word.size(),
                    result);
            break;
        }
    }
    return result;
}

string missingLetter(
        string word, unordered_set<string> dict, string& text, int findHelper)
{
    bool wordFinded = false;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string result;
    string newWord = "_" + word;
    int wordSize = newWord.size();
    int alphabetSize = alphabet.size();
    for (int i = 0; i < wordSize; i++) {
        for (int j = 0; j < alphabetSize; j++) {
            newWord[i] = alphabet[j];
            if (dict.find(newWord) != dict.end()) {
                result = newWord;
                int wordPosition = text.find(word, findHelper);

                text.replace(
                        text.begin() + wordPosition,
                        text.begin() + wordPosition + word.size(),
                        result);
                wordFinded = true;
                break;
            }
        }
        if (wordFinded) {
            break;
        } else {
            swap(newWord[i], newWord[i + 1]);
        }
    }
    return result;
}

string swapLetters(
        string word, unordered_set<string> dict, string& text, int findHelper)
{
    int wordSize = word.size();
    string result;
    for (int i = 0; i < wordSize; i++) {
        string newWord = word;
        swap(newWord[i], newWord[i + 1]);
        if (dict.find(newWord) != dict.end()) {
            result = newWord;
            int wordPosition = text.find(word, findHelper);

            text.replace(
                    text.begin() + wordPosition,
                    text.begin() + wordPosition + word.size(),
                    result);
        }
    }
    return result;
}

string wrongLetter(
        string word, unordered_set<string> dict, string& text, int findHelper)
{
    bool wordFinded = false;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string result;
    string newWord = word;
    int wordSize = newWord.size();
    int alphabetSize = alphabet.size();
    for (int i = 0; i < wordSize; i++) {
        newWord = word;
        for (int j = 0; j < alphabetSize; j++) {
            newWord[i] = alphabet[j];
            if (dict.find(newWord) != dict.end()) {
                result = newWord;
                int wordPosition = text.find(word, findHelper);
                text.replace(
                        text.begin() + wordPosition,
                        text.begin() + wordPosition + word.size(),
                        result);
                wordFinded = true;
                break;
            }
        }
        if (wordFinded) {
            break;
        }
    }
    return result;
}

string checkText(string filename, unordered_set<string> dict, string& text)
{
    int pos = 0;
    ifstream read;
    string wordContainer;
    read.open(filename);
    if (read.is_open()) {
        string word;
        while (read >> word) {
            lowerCase(word);
            cout << word;
            if (dict.find(word) != dict.end()) {
                cout << "\033[1;32m -> correct word \033[0m\n";
            } else {
                wordContainer = swapLetters(word, dict, text, pos);
                if (wordContainer.empty()) {
                    wordContainer = excessLetter(word, dict, text, pos);
                    if (wordContainer.empty()) {
                        wordContainer = missingLetter(word, dict, text, pos);
                        if (wordContainer.empty()) {
                            wordContainer = wrongLetter(word, dict, text, pos);
                            if (wordContainer.empty()) {
                                cout << "\033[1;31m -> unknown or\033[0m"
                                     << "\033[1;31m nonexisted word \033[0m\n";
                            } else {
                                cout << "\033[1;33m -> uncorrect word, \033[0m"
                                     << "\033[1;33mmaybe you mean -->> \033[0m"
                                     << wordContainer << endl;
                            }
                        } else {
                            cout << "\033[1;33m -> uncorrect word, \033[0m"
                                 << "\033[1;33mmaybe you mean -->> \033[0m"
                                 << wordContainer << endl;
                        }
                    } else {
                        pos--;
                        cout << "\033[1;33m -> uncorrect word, \033[0m"
                             << "\033[1;33mmaybe you mean -->> \033[0m"
                             << wordContainer << endl;
                    }

                } else {
                    cout << "\033[1;33m -> uncorrect word, \033[0m"
                         << "\033[1;33mmaybe you mean -->> \033[0m"
                         << wordContainer << endl;
                }
            }
            pos += word.size() + 1;
        }
    } else {
        cout << "Could not open file : " << filename << endl;
    }
    return text;
}
