#pragma once
#include <string>
#include <list>
#include "Meaning.h"
class Word
{
public:
	std::string word;
	std::string lang;
	std::list<Meaning> meanings;
	Word(std::string wordName, std::string wordLang, std::list<Meaning> wordMeanings);
	~Word();
};
