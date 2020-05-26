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
    string text = "helplo";
    REQUIRE(excessLetter("helplo", introduceDictionary(dictFile), text) == "hello");
    text = "appple";
    REQUIRE(excessLetter("appple", introduceDictionary(dictFile), text) == "apple");
    text = "adapft";
    REQUIRE(excessLetter("adapft", introduceDictionary(dictFile), text) == "adapt");
    text = "beltl";
    REQUIRE(excessLetter("beltl", introduceDictionary(dictFile), text) == "bell");
    text = "blokod";
    REQUIRE(excessLetter("blokod", introduceDictionary(dictFile), text) == "blood");
    text = "sfmooth";
    REQUIRE(excessLetter("sfmooth", introduceDictionary(dictFile), text) == "smooth");
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
    string text = "blok";
    REQUIRE(missingLetter("blok", introduceDictionary(dictFile), text) == "block");
    text = "pple";
    REQUIRE(missingLetter("pple", introduceDictionary(dictFile), text) == "apple");
    text = "joe";
    REQUIRE(missingLetter("joe", introduceDictionary(dictFile), text) == "joke");
    text = "wor";
    REQUIRE(missingLetter("wor", introduceDictionary(dictFile), text) == "work");
}

TEST_CASE("swapLetters", "CorrectWork")
{
    string dictFile = "dictionary.txt";
    string text = "helol";
    REQUIRE(swapLetters("helol", introduceDictionary(dictFile), text) == "hello");
    text = "aplpe";
    REQUIRE(swapLetters("aplpe", introduceDictionary(dictFile), text) == "apple");
    text = "actino";
    REQUIRE(swapLetters("actino", introduceDictionary(dictFile), text) == "action");
    text = "abues";
    REQUIRE(swapLetters("abues", introduceDictionary(dictFile), text) == "abuse");
}

TEST_CASE("WrongLetter", "Correct")
{
    string dictFile = "dictionary.txt";
    string text = "frink";
    REQUIRE(wrongLetter("frink", introduceDictionary(dictFile), text) == "drink");
    text = "abone";
    REQUIRE(wrongLetter("abone", introduceDictionary(dictFile), text) == "alone");
    text = "delp";
    REQUIRE(wrongLetter("delp", introduceDictionary(dictFile), text) == "help");
    text = "suiside";
    REQUIRE(wrongLetter("suiside", introduceDictionary(dictFile), text) == "suicide");
    text = "death";
    REQUIRE(wrongLetter("death", introduceDictionary(dictFile), text) == "death");
}
