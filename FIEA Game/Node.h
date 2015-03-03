#pragma once

class Node
{
public:
	Node(int);
	Node *next_node_;
	int GetValue() const;
	void SetValue(int value);
private:
	int value_;
};