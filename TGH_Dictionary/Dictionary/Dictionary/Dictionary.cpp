// Dictionary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include "Word.h"

void section_command(std::string Cmd, std::string &wd1, std::string &wd2)
{
	std::string sub_str;
	std::vector<std::string> words;
	char search = ' ';
	size_t i, j;

	// Split Command into vector
	for (i = 0; i < Cmd.size(); i++)
	{
		if (Cmd.at(i) != search)
		{
			sub_str.insert(sub_str.end(), Cmd.at(i));
		}
		if (i == Cmd.size() - 1)
		{
			words.push_back(sub_str);
			sub_str.clear();
		}
		if (Cmd.at(i) == search)
		{
			words.push_back(sub_str);
			sub_str.clear();
		}
	}
	// Clear out blanks
	for (i = words.size() - 1; i > 0; i--)
	{
		if (words.at(i) == "")
		{
			words.erase(words.begin() + i);
		}
	}
	// Make words upper case
	for (i = 0; i < words.size(); i++)
	{
		for (j = 0; j < words.at(i).size(); j++)
		{
			if (islower(words.at(i).at(j)))
			{
				words.at(i).at(j) = toupper(words.at(i).at(j));
			}
		}
	}
	// Get 2 words.
	if (words.size() == 0)
	{
		std::cout << "No command given" << std::endl;
	}
	if (words.size() == 1)
	{
		wd1 = words.at(0);
	}
	if (words.size() == 2)
	{
		wd1 = words.at(0);
		wd2 = words.at(1);
	}
	if (words.size() > 2)
	{
		std::cout << "Command too long. Only type one or two words (verb and noun)" << std::endl;
	}
}

void initializeDictionary(std::list<Word> &words){
	std::list<Meaning> meanings;
	meanings.push_back(Meaning("Mens van het mannelijk geslacht", "Een man begrijpt niet zomaar een vrouw"));
	meanings.push_back(Meaning("Mens zonder onderscheid van het geslacht","We waren met acht man"));
	meanings.push_back(Meaning("Echtgenoot", "Mijn man"));
	words.push_back(Word("Man", "NL", meanings));

	meanings.clear();
	meanings.push_back(Meaning("Inrichting waar onderwijs wordt gegeven","Een lagere school: basisschool"));
	meanings.push_back(Meaning("Het gebouw","Heey kijk, een school"));
	meanings.push_back(Meaning("Onderwijs, les","We hebben vandaag geen school"));
	meanings.push_back(Meaning("Richting in letterkunde, kunst enz.","De romantische school"));
	meanings.push_back(Meaning("De gezamenlijke volgelingen van een meester","Jesus, hoe gaat het met je school?"));
	words.push_back(Word("School", "NL", meanings));

	meanings.clear();
	meanings.push_back(Meaning("Mens van het vrouwelijk geslacht","Een man begrijpt niet zomaar een vrouw"));
	meanings.push_back(Meaning("Echtgenote", "Groeten aan je vrouw"));
	meanings.push_back(Meaning("(kaartspel) Naam van een kaart; koningin", "Ruitenvrouw"));
	meanings.push_back(Meaning("Bazin, vrouwtje (3)", "(tegen een hond) kom maar bij de vrouw"));
	words.push_back(Word("Vrouw", "NL", meanings));

	meanings.clear();
	meanings.push_back(Meaning("erwachsene mannliche Person","Ein netter junger Mann"));
	meanings.push_back(Meaning("jds Ehemann","Darf ich ihnen meinen Mann vorstellen?"));
	meanings.push_back(Meaning("Mensch, Person","Das kostet 15 Euro pro Mann."));
	words.push_back(Word("Man/Mann", "DE", meanings));

	meanings.clear();
	meanings.push_back(Meaning("erwachsene, weibliche Person","Eine junge, alleinstehende Frau"));
	meanings.push_back(Meaning("jds Ehefrau", "Darf ich ihnen meine Frau vorstellen?"));
	words.push_back(Word("Vrouw/Frau", "DE", meanings));

	meanings.clear();
	meanings.push_back(Meaning("Institution, die bes","Sie geht gern in die / zur Schule"));
	meanings.push_back(Meaning("Unterricht in einter Schule","Die Schule beginnt um 8 Uhr"));
	meanings.push_back(Meaning("Gebaude, in dem eine Schule ist","Ds ist eine Schule"));
	meanings.push_back(Meaning("Gruppe von Wissenschaftlern","Die Komponisten der Wiener Schule"));
	words.push_back(Word("School/Schule", "DE", meanings));

	meanings.clear();
	meanings.push_back(Meaning("An adult male human being","Hundreds of men, women and children"));
	meanings.push_back(Meaning("Human beings taken as a whole; the human race", "The development of man"));
	meanings.push_back(Meaning("Obviously masculine male person", "He's independent, tough, strong, brave; a real man"));
	meanings.push_back(Meaning("A word sometimes used informally or whilst giving commands to someone","Get on with your work, man, and stop complaining!"));
	meanings.push_back(Meaning("An ordinary soldior, who is not an officer","Officers and men"));
	meanings.push_back(Meaning("A piece used in playing chess or draughts","I took three of his men in one move"));
	words.push_back(Word("Man/Man","EN", meanings));

	meanings.clear();
	meanings.push_back(Meaning("An adult human female","His sisters are both frown women now"));
	meanings.push_back(Meaning("A female domestic daily helper","We have a woman who comes in to do the cleaning"));
	words.push_back(Word("Vrouw/Woman","EN",meanings));

	meanings.clear();
	meanings.push_back(Meaning("An institution where instruction is given, especially to persons under college age","The children are at school"));
	meanings.push_back(Meaning("An institution for instruction in a particular skill or field","You can become an engineer at that specific school"));
	meanings.push_back(Meaning("A college or university","You could call it college but school sounds simpler"));
	meanings.push_back(Meaning("A regular course of meetings of a teacher or teachers and students for instruction","Summer school"));
	meanings.push_back(Meaning("A sessions of such a course", "No school today; to be kept after school"));
	meanings.push_back(Meaning("The activity or precess of learning under instruction","As a child, i never liked school"));
	meanings.push_back(Meaning("One's formal education","They plan to be married when he finishes school"));
	words.push_back(Word("School/School","EN",meanings));
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::string command;
	std::string word_1;
	std::string word_2;
	std::list<Word> words;
	bool initialized = false;

	while (word_1 != "QUIT"){
		command.clear();
		if (!initialized){
			std::cout << "Welcome to the official Dictionary Simulator 2014" << std::endl << "Here you can search words (WORD, LANG), where LANG = NL/DE/EN" << std::endl;
			initializeDictionary(words);
			initialized = true;
		}

		if (word_1 == "SHOW"){
			if (word_2 == "WORDS"){
				std::cout << "Words:" << std::endl;
				for (Word currentWord : words){
					std::cout << "\t" << currentWord.word << "\t" << currentWord.lang << std::endl;
				}
			}
			else if (word_2 == "LANGS"){
				std::cout << "Langs:" << std::endl;
				std::vector<std::string> langs;
				for (Word currentWord : words){
					bool alreadyExists = false;
					for (std::string lang : langs){
						if (lang == currentWord.lang)
							alreadyExists = true;
					}
					if (!alreadyExists)
						langs.push_back(currentWord.lang);
				}
				for (std::string lang : langs){
					std::cout << "\t" << lang << std::endl;
				}
			}
		}
		else{
			for (Word currentWord : words){
				std::string str = currentWord.word;
				std::transform(str.begin(), str.end(), str.begin(), ::toupper);
				bool containsWord = false;
				std::vector<std::string> strings;
				strings = split(str, '/');
				for (std::string curString : strings){
					if (curString == word_1)
						containsWord = true;
				}
				if (containsWord && word_2 == currentWord.lang){
					std::cout << "Word: " << currentWord.word << "\t" << currentWord.lang << std::endl;
					std::cout << "Meanings:" << std::endl;
					for (Meaning currentMeaning : currentWord.meanings){
						std::cout << "\t" << currentMeaning.name << ": " << "\"" + currentMeaning.description + "\"" << std::endl;
					}
				}
			}
		}

		std::cout << std::endl;
		getline(std::cin, command);
		std::cout << "Your raw command was " << command << std::endl << std::endl;
		word_1 = "";
		word_2 = "";
		section_command(command, word_1, word_2);
	}
	return 0;
}

