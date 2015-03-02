#include "HashElement.h"

HashElement::HashElement(int key, std::string value)
{
	key_ = key;
	value_ = value;
	next_element_ = nullptr;
}

HashElement::~HashElement()
{
}

int HashElement::GetKey(){
	return key_;
}

std::string HashElement::GetValue(){
	return value_;
}