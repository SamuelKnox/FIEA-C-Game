#pragma once

#include <string>

#include "Node.h"

class LinkedList
{
private:
	Node *head;
	int count;
public:
	LinkedList();
	~LinkedList();
	int get_count();
	void AddNode(int);
	std::string GetList();
	bool Contains(int);
	void Remove(int);
	int GetValue(int);
};