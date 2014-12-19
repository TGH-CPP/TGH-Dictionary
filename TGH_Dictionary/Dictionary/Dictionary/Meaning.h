#pragma once
#include <string>
class Meaning
{
public:
	std::string name;
	std::string description;
	Meaning(std::string meaningName, std::string meaningDescription);
	~Meaning();
};

