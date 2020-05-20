#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
#pragma once
unordered_set<string> introduceDictionary(string filename);
string excessLetter(string word, unordered_set<string> Dictionary);
void checkText(string filename, unordered_set<string> Dictionary);
