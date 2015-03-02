#include "LinkedList.h"

LinkedList::LinkedList()
{
	head_ = new Node(0);
}

LinkedList::~LinkedList()
{
	Node *currentNode = head_;
	Node *nextNode = head_;
	while (nextNode->next_node_){
		nextNode = nextNode->next_node_;
		delete currentNode;
		currentNode = nextNode;
	}
	delete currentNode;
}

int LinkedList::GetCount() const{
	return count_;
}

void LinkedList::AddNode(int value){
	Node *node = new Node(value);
	Node *previousNode = head_;
	while (previousNode->next_node_ && previousNode->next_node_->GetValue() <= node->GetValue()){
		previousNode = previousNode->next_node_;
	}
	if (previousNode->next_node_){
		node->next_node_ = previousNode->next_node_;
	}
	previousNode->next_node_ = node;
	count_++;
}

std::string LinkedList::GetList(){
	std::string list;
	Node *currentNode = head_;
	while (currentNode->next_node_){
		currentNode = currentNode->next_node_;
		list += std::to_string(currentNode->GetValue()) + " ";
	}
	return list;
}

bool LinkedList::Contains(int number){
	Node *currentNode = head_;
	while (currentNode->next_node_){
		currentNode = currentNode->next_node_;
		if (currentNode->GetValue() == number){
			return true;
		}
		if (currentNode->GetValue() > number){
			return false;
		}
	}
	return false;
}

void LinkedList::Remove(int number){
	Node *previousNode = head_;
	Node *currentNode = head_;
	while (currentNode->next_node_){
		previousNode = currentNode;
		currentNode = currentNode->next_node_;
		if (currentNode->GetValue() == number){
			previousNode->next_node_ = currentNode->next_node_;
			delete currentNode;
			count_--;
			return;
		}
	}
}

int LinkedList::GetValue(int index) const{
	Node *currentNode = head_;
	int currentIndex = -1;
	while (currentNode->next_node_){
		currentNode = currentNode->next_node_;
		currentIndex++;
		if (index == currentIndex){
			return currentNode->GetValue();
		}
	}
	return -1;
}