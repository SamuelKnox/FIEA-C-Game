#include "HashMap.h"
#include "PrimeChecker.h"

HashMap::HashMap(int _size)
{
	while (!PrimeChecker::IsPrime(_size)){
		_size++;
	}
	size = _size;
	map = new HashElement*[size]();
}

HashMap::~HashMap()
{
}

int HashMap::GetHash(int _key){
	return _key % size;
}

void HashMap::Put(int _key, std::string _value){
	int hash = GetHash(_key);
	if (!map[hash]){
		map[hash] = new HashElement(_key, _value);
	}
	else{
		HashElement *lastElement = map[hash];
		while (lastElement->next_element){
			lastElement = lastElement->next_element;
		}
		lastElement->next_element = new HashElement(_key, _value);
	}
	count++;
}

std::string HashMap::GetElement(int _key){
	int hash = GetHash(_key);
	if (map[hash]){
		HashElement *currentElement = map[hash];
		while (currentElement->get_key() != _key && currentElement->next_element){
			currentElement = currentElement->next_element;
		}
		return currentElement->get_value();
	}
	return nullptr;
}

bool HashMap::Contains(int _key){
	int hash = GetHash(_key);
	if (map[hash]){
		HashElement *currentElement = map[hash];
		while (currentElement->get_key() != _key && currentElement->next_element){
			currentElement = currentElement->next_element;
		}
		if (currentElement->get_key() == _key){
			return true;
		}
	}
	return false;
}

void HashMap::Remove(int _key){
	if (!Contains(_key)){
		return;
	}
	int hash = GetHash(_key);
	HashElement *currentElement = map[hash];
	if (!currentElement->get_key() == _key){
		HashElement *previousElement = currentElement;
		currentElement = currentElement->next_element;
		while (currentElement->get_key() != _key){
			previousElement = currentElement;
			currentElement = currentElement->next_element;
		}
		if (currentElement->next_element){
			previousElement->next_element = currentElement->next_element;
		}
	}
	delete currentElement;
	count--;
}

int HashMap::get_count(){
	return count;
}