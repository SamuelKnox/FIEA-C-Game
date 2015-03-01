#pragma once
class Node
{
private:
	int value;
public:
	Node(int);
	~Node();
	Node *next_node;
	int get_value();
	void set_value(int);
};

