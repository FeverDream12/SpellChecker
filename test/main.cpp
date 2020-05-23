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

TEST_CASE("ExcessLetter", "Correct")
{
    string dictFile = "dictionary.txt";
    REQUIRE(excessLetter("helplo", introduceDictionary(dictFile)) == "hello");
    REQUIRE(excessLetter("appple", introduceDictionary(dictFile)) == "apple");
    REQUIRE(excessLetter("adapft", introduceDictionary(dictFile)) == "adapt");
    REQUIRE(excessLetter("beltl", introduceDictionary(dictFile)) == "belt");
    REQUIRE(excessLetter("blokod", introduceDictionary(dictFile)) == "blood");
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

TEST_CASE("swapLetters", "CorrectWork")
{
    string dictFile = "dictionary.txt";
    REQUIRE(swapLetters("helol", introduceDictionary(dictFile)) == "hello");
    REQUIRE(swapLetters("aplpe", introduceDictionary(dictFile)) == "apple");
    REQUIRE(swapLetters("actino", introduceDictionary(dictFile)) == "action");
    REQUIRE(swapLetters("abues", introduceDictionary(dictFile)) == "abuse");
}

TEST_CASE("WrongLetter", "Correct")
{
    string dictFile = "dictionary.txt";
    REQUIRE(wrongLetter("frink", introduceDictionary(dictFile)) == "drink");
    REQUIRE(wrongLetter("abone", introduceDictionary(dictFile)) == "alone");
    REQUIRE(wrongLetter("delp", introduceDictionary(dictFile)) == "help");
    REQUIRE(wrongLetter("suiside", introduceDictionary(dictFile)) == "suicide");
    REQUIRE(wrongLetter("death", introduceDictionary(dictFile)) == "death");
}
