#include "textWork.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Enter text" << endl;
    inputText();
    string inputFile = "input.txt";
    string cleanText = "clean.txt";
    clearText(inputFile, cleanText);
    return 0;
}
