#include "HashElement.h"

HashElement::HashElement(int _key, std::string _value)
{
	key = _key;
	value = _value;
}

HashElement::~HashElement()
{
}

int HashElement::get_key(){
	return key;
}

std::string HashElement::get_value(){
	return value;
}