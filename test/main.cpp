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
    REQUIRE(excessLetter("aobvious", introduceDictionary(dictFile))
            == "obvious");
    REQUIRE(excessLetter("sfmooth", introduceDictionary(dictFile)) == "smooth");
}

TEST_CASE("lowerCase", "CorrectWork")
{
    string str_1 = "APPLE";
    REQUIRE(lowerCase(str_1) == "apple");
    string str_2 = "AiR";
    REQUIRE(lowerCase(str_2) == "air");
    string str_3 = "Achievement";
    REQUIRE(lowerCase(str_3) == "achievement");
    string str_4 = "CheRRy";
    REQUIRE(lowerCase(str_4) == "cherry");
    string str_5 = "abuse";
    REQUIRE(lowerCase(str_5) == "abuse");
}

TEST_CASE("Missing Letter", "Correct")
{
    string dictFile = "dictionary.txt";
    REQUIRE(missingLetter("blok", introduceDictionary(dictFile)) == "block");
    REQUIRE(missingLetter("pple", introduceDictionary(dictFile)) == "apple");
    REQUIRE(missingLetter("joe", introduceDictionary(dictFile)) == "joke");
    REQUIRE(missingLetter("wor", introduceDictionary(dictFile)) == "work");
}
