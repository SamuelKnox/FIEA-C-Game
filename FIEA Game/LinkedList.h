#pragma once

#include <string>

#include "Node.h"

class LinkedList
{
private:
	Node *head_;
	int count_;
public:
	LinkedList();
	~LinkedList();
	int GetCount() const;
	void AddNode(int);
	std::string GetList();
	bool Contains(int);
	void Remove(int);
	int GetValue(int) const;
};