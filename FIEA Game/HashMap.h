#pragma once
#include <string>

#include "HashElement.h"

class HashMap
{
private:
	HashElement **map;
	int size;
	int count;
public:
	HashMap(int);
	~HashMap();
	int GetHash(int);
	void Put(int, std::string);
	std::string GetElement(int);
	bool Contains(int);
	void Remove(int);
	int get_count();
};

