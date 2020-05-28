#include "source.h"
#include "textWork.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Enter text:\n";
    string text = inputText();
    text = lowerCase(text);
    string inputFile = "input.txt";
    string cleanText = "clean.txt";
    string dictFile = "dictionary.txt";
    clearText(inputFile, cleanText);
    text = checkText(cleanText, introduceDictionary(dictFile), text);
    cout << "\nCorrected text: \n" << text << endl;
    return 0;
}
