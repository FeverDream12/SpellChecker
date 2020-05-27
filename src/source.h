#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
#pragma once
unordered_set<string> introduceDictionary(string filename);
string excessLetter(string word, unordered_set<string> dict, string& text);
string checkText(string filename, unordered_set<string> dict, string& text);
string missingLetter(string word, unordered_set<string> dict, string& text);
string swapLetters(string word, unordered_set<string> dict, string& text);
string wrongLetter(string word, unordered_set<string> dict, string& text);
