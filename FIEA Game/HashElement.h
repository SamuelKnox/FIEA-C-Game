#pragma once

#include <string>

class HashElement
{
private:
	int key;
	std::string value;
public:
	HashElement(int, std::string);
	~HashElement();
	HashElement *next_element;
	int get_key();
	std::string get_value();
};

