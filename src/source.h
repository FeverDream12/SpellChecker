#include <iostream>
#include <string>
#include <unordered_set>
#pragma once
std::unordered_set<std::string> introduceDictionary(std::string filename);
std::string excessLetter(std::string word, std::unordered_set<std::string> dict, std::string& text);
std::string checkText(std::string filename, std::unordered_set<std::string> dict, std::string& text);
std::string missingLetter(std::string word, std::unordered_set<std::string> dict, std::string& text);
std::string swapLetters(std::string word, std::unordered_set<std::string> dict, std::string& text);
std::string wrongLetter(std::string word, std::unordered_set<std::string> dict, std::string& text);
