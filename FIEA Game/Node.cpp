#include "Node.h"

Node::Node(int value)
{
	value_ = value;
}

Node::~Node()
{
}

int Node::GetValue(){
	return value_;
}
void Node::SetValue(int value){
	value_ = value;
}