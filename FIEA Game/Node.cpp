#include "Node.h"


Node::Node(int _value)
{
	value = _value;
}


Node::~Node()
{
}

int Node::get_value(){
	return value;
}
void Node::set_value(int _value){
	value = _value;
}