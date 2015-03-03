#pragma once

#include <string>

#include "Node.h"

class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	int GetCount() const;
	void AddNode(int value);
	std::string GetList() const;
	bool Contains(int value) const;
	void Remove(int value);
	int GetValue(int index) const;
private:
	Node *head_;
	int count_;
};