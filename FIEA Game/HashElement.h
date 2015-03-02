#pragma once

#include <string>

class HashElement
{
private:
	int key_;
	std::string value_;
public:
	HashElement(int, std::string);
	~HashElement();
	HashElement *next_element_;
	int GetKey();
	std::string GetValue();
};

