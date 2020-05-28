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

TEST_CASE("ExcessLetter", "CorrectWork")
{
    string dict = "dictionary.txt";
    string text = "helplo";
    REQUIRE(excessLetter("helplo", introduceDictionary(dict), text, 0) == "hello");
    text = "appple";
    REQUIRE(excessLetter("appple", introduceDictionary(dict), text, 0) == "apple");
    text = "adapft";
    REQUIRE(excessLetter("adapft", introduceDictionary(dict), text, 0) == "adapt");
    text = "beltl";
    REQUIRE(excessLetter("beltl", introduceDictionary(dict), text, 0) == "bell");
    text = "blokod";
    REQUIRE(excessLetter("blokod", introduceDictionary(dict), text, 0) == "blood");
    text = "boook";
    REQUIRE(excessLetter("boook", introduceDictionary(dict), text, 0) == "book");
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

TEST_CASE("MissingLetter", "CorrectWork")
{
    string dict = "dictionary.txt";
    string text = "blok";
    REQUIRE(missingLetter("blok", introduceDictionary(dict), text, 0) == "block");
    text = "pple";
    REQUIRE(missingLetter("pple", introduceDictionary(dict), text, 0) == "apple");
    text = "joe";
    REQUIRE(missingLetter("joe", introduceDictionary(dict), text, 0) == "joke");
    text = "wor";
    REQUIRE(missingLetter("wor", introduceDictionary(dict), text, 0) == "word");
}

TEST_CASE("SwapLetters", "CorrectWork")
{
    string dict = "dictionary.txt";
    string text = "helol";
    REQUIRE(swapLetters("helol", introduceDictionary(dict), text, 0) == "hello");
    text = "aplpe";
    REQUIRE(swapLetters("aplpe", introduceDictionary(dict), text, 0) == "apple");
    text = "actino";
    REQUIRE(swapLetters("actino", introduceDictionary(dict), text, 0) == "action");
    text = "abues";
    REQUIRE(swapLetters("abues", introduceDictionary(dict), text, 0) == "abuse");
}

TEST_CASE("WrongLetter", "Correct")
{
    string dict = "dictionary.txt";
    string text = "frink";
    REQUIRE(wrongLetter("frink", introduceDictionary(dict), text, 0) == "drink");
    text = "abone";
    REQUIRE(wrongLetter("abone", introduceDictionary(dict), text, 0) == "alone");
    text = "delp";
    REQUIRE(wrongLetter("delp", introduceDictionary(dict), text, 0) == "help");
    text = "beld";
    REQUIRE(wrongLetter("beld", introduceDictionary(dict), text, 0) == "bend");
    text = "death";
    REQUIRE(wrongLetter("death", introduceDictionary(dict), text, 0) == "death");
}
