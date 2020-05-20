#define CATCH_CONFIG_MAIN
#include "../src/source.h"
#include "../src/textWork.h"
#include "../thirdparty/catch.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

unordered_set<string> Dictionary;

TEST_CASE("Helplo", "Correct")
{
    string dictFile = "dictionary.txt";
    REQUIRE(excessLetter("helplo", introduceDictionary(dictFile)) == "hello");
    REQUIRE(excessLetter("appple", introduceDictionary(dictFile)) == "apple");
    REQUIRE(excessLetter("adapft", introduceDictionary(dictFile)) == "adapt");
    REQUIRE(excessLetter("beltl", introduceDictionary(dictFile)) == "belt");
    REQUIRE(excessLetter("aobvious", introduceDictionary(dictFile)) == "obvious");
    REQUIRE(excessLetter("sfmooth", introduceDictionary(dictFile)) == "smooth");
}
