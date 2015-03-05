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
		HashElement *current_element = map_[hash];
		HashElement *next_element = map_[hash];
		while (next_element->next_element_){
			next_element = next_element->next_element_;
			delete current_element;
			current_element = next_element;
		}
		delete current_element;
	}
}

int HashMap::GetHash(int key) const{
	return key % size_;
}

void HashMap::Insert(int key, std::string value){
	int hash = GetHash(key);
	if (!map_[hash]){
		map_[hash] = new HashElement(key, value);
	}
	else{
		HashElement *last_element = map_[hash];
		while (last_element->next_element_){
			last_element = last_element->next_element_;
		}
		last_element->next_element_ = new HashElement(key, value);
	}
	count_++;
}

std::string HashMap::Find(int key) const{
	int hash = GetHash(key);
	if (map_[hash]){
		HashElement *current_element = map_[hash];
		while (current_element->GetKey() != key){
			current_element = current_element->next_element_;
		}
		return current_element->GetValue();
	}
	return nullptr;
}

bool HashMap::Contains(int key) const{
	int hash = GetHash(key);
	if (map_[hash]){
		HashElement *current_element = map_[hash];
		while (current_element->GetKey() != key && current_element->next_element_){
			current_element = current_element->next_element_;
		}
		if (current_element->GetKey() == key){
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
	HashElement *current_element = map_[hash];
	if (current_element->GetKey() == key){
		map_[hash] = current_element->next_element_;
		delete current_element;
	}
	else{
		HashElement *previous_element = current_element;
		current_element = current_element->next_element_;
		while (current_element->GetKey() != key){
			previous_element = current_element;
			current_element = current_element->next_element_;
		}
		previous_element->next_element_ = current_element->next_element_;
		delete current_element;
	}
	count_--;
}

int HashMap::GetCount() const{
	return count_;
}