#pragma once
#include <string>

#include "HashElement.h"

class HashMap
{
public:
	HashMap(int size);
	~HashMap();
	int GetHash(int key) const;
	void Insert(int key, std::string value);
	std::string Find(int key) const;
	bool Contains(int key) const;
	void Remove(int key);
	int GetCount() const;
private:
	HashElement **map_;
	int size_;
	int count_;
};