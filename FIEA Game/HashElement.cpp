#include "HashElement.h"

HashElement::HashElement(int key, std::string value) :
key_(key), value_(value), next_element_(nullptr){}

int HashElement::GetKey() const{
	return key_;
}

std::string HashElement::GetValue() const{
	return value_;
}