#include "HashMap.h"
#include "PrimeChecker.h"

HashMap::HashMap(int size)
{
	while (!PrimeChecker::IsPrime(size)){
		size++;
	}
	size_ = size;
	map_ = new HashElement*[size_]();
}

HashMap::~HashMap()
{
	for (int i = 0; i < size_; i++){
		int hash = GetHash(i);
		if (!map_[hash]){
			continue;
		}
		HashElement *currentElement = map_[hash];
		HashElement *nextElement = map_[hash];
		while (nextElement->next_element_){
			nextElement = nextElement->next_element_;
			delete currentElement;
			currentElement = nextElement;
		}
		delete currentElement;
	}
}

int HashMap::GetHash(int key){
	return key % size_;
}

void HashMap::Put(int key, std::string value){
	int hash = GetHash(key);
	if (!map_[hash]){
		map_[hash] = new HashElement(key, value);
	}
	else{
		HashElement *lastElement = map_[hash];
		while (lastElement->next_element_){
			lastElement = lastElement->next_element_;
		}
		lastElement->next_element_ = new HashElement(key, value);
	}
	count_++;
}

std::string HashMap::GetElement(int key){
	int hash = GetHash(key);
	if (map_[hash]){
		HashElement *currentElement = map_[hash];
		while (currentElement->GetKey() != key && currentElement->next_element_){
			currentElement = currentElement->next_element_;
		}
		return currentElement->GetValue();
	}
	return nullptr;
}

bool HashMap::Contains(int key){
	int hash = GetHash(key);
	if (map_[hash]){
		HashElement *currentElement = map_[hash];
		while (currentElement->GetKey() != key && currentElement->next_element_){
			currentElement = currentElement->next_element_;
		}
		if (currentElement->GetKey() == key){
			return true;
		}
	}
	return false;
}

void HashMap::Remove(int key){
	if (!Contains(key)){
		return;
	}
	int hash = GetHash(key);
	HashElement *currentElement = map_[hash];
	if (currentElement->GetKey() == key){
		delete currentElement;
		map_[hash] = nullptr;
	}
	else{
		HashElement *previousElement = currentElement;
		currentElement = currentElement->next_element_;
		while (currentElement->GetKey() != key){
			previousElement = currentElement;
			currentElement = currentElement->next_element_;
		}
		previousElement->next_element_ = currentElement->next_element_;
		delete currentElement;
	}
	count_--;
}

int HashMap::GetCount(){
	return count_;
}