#include "Node.h"

Node::Node(int value) :
value_(value){}

int Node::GetValue() const{
	return value_;
}
void Node::SetValue(int value){
	value_ = value;
}