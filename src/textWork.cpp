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
