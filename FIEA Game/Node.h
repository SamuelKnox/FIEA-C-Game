#pragma once

class Node
{
private:
	int value_;
public:
	Node(int);
	~Node();
	Node *next_node_;
	int GetValue();
	void SetValue(int);
};