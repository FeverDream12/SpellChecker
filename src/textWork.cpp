#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string lowerCase(string& str)
{
    for (auto& chr : str) {
        chr = tolower(chr);
    }
    return str;
}

void inputText()
{
    ofstream write;
    string inputFile = "input.txt";
    write.open(inputFile);
    string text;

    getline(cin, text);
    write << text;

    write.close();
}
