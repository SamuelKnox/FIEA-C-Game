#pragma once

#include <string>

class HashElement
{
public:
	HashElement(int key, std::string value);
	HashElement *next_element_;
	int GetKey() const;
	std::string GetValue() const;
private:
	int key_;
	std::string value_;
};