#include "textWork.h"
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

unordered_set<string> Dictionary;

void introduceDictionary(string filename)
{
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
}
