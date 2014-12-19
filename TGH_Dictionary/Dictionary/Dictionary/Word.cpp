#include "stdafx.h"
#include "Word.h"
#include <iostream>

Word::Word(std::string wordName, std::string wordLang, std::list<Meaning> wordMeanings)
{
	word = wordName;
	lang = wordLang;
	meanings = wordMeanings;
}

Word::~Word()
{
}