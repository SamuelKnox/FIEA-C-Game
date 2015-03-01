#include <iostream>

#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = new Node(0);
}

LinkedList::~LinkedList()
{
}

int LinkedList::get_count(){
	return count;
}

void LinkedList::AddNode(int _value){
	Node *node = new Node(_value);
	Node *previousNode = head;
	while (previousNode->next_node && previousNode->next_node->get_value() <= node->get_value()){
		previousNode = previousNode->next_node;
	}
	if (previousNode->next_node){
		node->next_node = previousNode->next_node;
	}
	previousNode->next_node = node;
	count++;
}

std::string LinkedList::GetList(){
	std::string list;
	Node *currentNode = head;
	while (currentNode->next_node){
		currentNode = currentNode->next_node;
		list += std::to_string(currentNode->get_value()) + " ";
	}
	return list;
}

bool LinkedList::Contains(int number){
	Node *currentNode = head;
	while (currentNode->next_node){
		currentNode = currentNode->next_node;
		if (currentNode->get_value() == number){
			return true;
		}
		if (currentNode->get_value() > number){
			return false;
		}
	}
	return false;
}

void LinkedList::Remove(int number){
	Node *previousNode = head;
	Node *currentNode = head;
	while (currentNode->next_node){
		previousNode = currentNode;
		currentNode = currentNode->next_node;
		if (currentNode->get_value() == number){
			previousNode->next_node = currentNode->next_node;
			delete currentNode;
			count--;
			return;
		}
	}
}

int LinkedList::GetValue(int index){
	Node *currentNode = head;
	int currentIndex = -1;
	while (currentNode->next_node){
		currentNode = currentNode->next_node;
		currentIndex++;
		if (index == currentIndex){
			return currentNode->get_value();
		}
	}
	return -1;
}