#include <iostream>
#include <string>
#include <time.h>

#include "Player.h"
#include "LinkedList.h"
#include "HashMap.h"

using std::cout;
using std::cin;
using std::endl;

std::string AskName();
void AskForHelp();
void SimonSayz();
std::string GetFizzBuzz(int);
LinkedList CreateLinkedList();
void RemoveElementFromLinkedList(LinkedList*);
HashMap PutLinkedListInHashMap(LinkedList*);
void RemoveElementFromHashMap(HashMap*);
void EndGame();

Player player;

const std::string NO_FIZZ_BUZZ_VALUE = "No associated FizzBuzz";

int main()
{
	srand((unsigned int)time(NULL));
	cout << "---FIEA C++ Game---" << endl << endl;
	player.set_name(AskName());
	AskForHelp();
	SimonSayz();
	LinkedList linkedList = CreateLinkedList();
	RemoveElementFromLinkedList(&linkedList);
	HashMap hashMap = PutLinkedListInHashMap(&linkedList);
	RemoveElementFromHashMap(&hashMap);
	EndGame();
	cout << endl;
	system("PAUSE");
	exit(0);
}

std::string AskName(){
	cout << "Welcome to Newbland!  What is your name?" << endl;
	std::string name;
	getline(cin, name);
	return name;
}

void AskForHelp(){
	cout << endl << "Greetings " << player.get_name() << ".  I know we just met, but I am in need of your assistance.  Will you help me?" << endl;
	cout << "1. Yes.  I am always willing to help someone in need." << endl;
	cout << "2. I am no fool!  Help you with what?" << endl;
	cout << "3. I don't have time for you." << endl;
	int choice;
	while (!(cin >> choice) || choice < 1 || choice > 3){
		cout << endl << "Hint:  Enter the number of what you would like to do." << endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	cout << endl;
	if (choice == 1){
		cout << endl;
		return;
	}
	else if (choice == 2){
		cout << "Forget it...I am not looking for the fearful.  Come back when you are brave enough to venture into the unknown." << endl << endl;
		system("PAUSE");
		exit(0);
	}
	else if (choice == 3){
		cout << "Fine!  I will go find a real adventurer to rescue me!" << endl << endl;
		system("PAUSE");
		exit(0);
	}
}

void SimonSayz(){
	cout << "Evil Simon sayz that if we do not repeat what he sayz, he was curse our village.  You must say exactly what he says, or we are all doomed!" << endl << endl;
	std::string fizzBuzz;
	for (int i = 0; i < 3; i++){
		int number = rand() % 10000 + 1;
		std::string fizzBuzz = GetFizzBuzz(number);
		if(fizzBuzz.compare(NO_FIZZ_BUZZ_VALUE) == 0){
			i--;
			continue;
		}
		cout << "Simon sayz " << fizzBuzz << endl;
		std::string repeat;
		cin >> repeat;
		while (fizzBuzz.compare(repeat) != 0){
			cin >> repeat;
		}
		cout << endl;
	}
	cout << "Simon sayz Jinx!" << endl << endl;
	cout << "Oh no!  This is terrible!  Simon just jinxed you!  Now you can't say anything until someone says your name!  But I can't remember it.  What was your name again?" << endl;
	std::string x;
	cin.ignore();
	getline(cin, x);
}

std::string GetFizzBuzz(int number){
	std::string fizzBuzz;
	if (number % (3 * 5) == 0){
		fizzBuzz = "FizzBuzz";
	}
	else if (number % 3 == 0){
		fizzBuzz = "Fizz";
	}
	else if (number % 5 == 0){
		fizzBuzz = "Buzz";
	}
	else{
		fizzBuzz = NO_FIZZ_BUZZ_VALUE;
	}
	return fizzBuzz;
}

LinkedList CreateLinkedList(){
	cout << endl << "You can't talk when you are jinxed!  Now, the only way to break the curse is to form a linked list!  It's really quite simple.  Just tell me a bunch of positive integers, one at a time.  Don't worry about ordering the numbers.  I've got that covered.  You can say 0 when you are happy with your linked list." << endl;
	LinkedList *linkedList = new LinkedList();
	int number;
	cin >> number;
	while (number > 0){
		linkedList->AddNode(number);
		cin >> number;
	}
	if (linkedList->get_count() < 3){
		cout << endl << "Errr...your list is pretty weak.  It needs to be at least 3 numbers long to ward of the jinx.  Give me another number." << endl;
		cin >> number;
		while (number <= 0){
			cin >> number;
		}
		linkedList->AddNode(number);
	}
	cout << endl << "Hmmm....not bad.  The linked list you made was:" << endl << linkedList->GetList() << endl << endl;
	return *linkedList;
}

void RemoveElementFromLinkedList(LinkedList *_linkedList){
	cout << "That should keep the jinx at bay for a little while, but not for long.  The linked list is too long.  Fortunately for you, I am trained in the art of removing numbers from linked lists.  Just tell me which number you want me to remove, and I will take care of it for you." << endl;
	int number;
	cin >> number;
	cout << endl;
	while (!_linkedList->Contains(number)){
		cout << "I am a talented remover of elements, but removing something that doesn't exist...not even evil Simon could do that.  Pick a number that exists in your linked list.  You must choose from the following:" << endl << _linkedList->GetList() << endl;
		cin >> number;
		cout << endl;
	}
	cout << "Good.  Now watch this.." << endl << "Abra kadabra!  Voodoo magic! " << number << " be gone!" << endl << endl << "Whew!  That took a lot out of me.  But it worked!  Take a look at my handy work:";
	_linkedList->Remove(number);
	cout << _linkedList->GetList() << endl << endl << "Your new list is strong enough to destroy the jinx!" << endl;
}

HashMap PutLinkedListInHashMap(LinkedList *_linkedList){
	cout << "These are actually some great numbers.  In combination with FizzBuzz, they should be able to defeat any evils we may see in the future.  But as they are now, the numbers will soon expire.  If we put them in a HashMap along with their associated FizzBuzz values, we should be able to keep them safe for a long time.  I will go ahead and do that for you.";
	HashMap *hashMap = new HashMap(_linkedList->get_count());
	for (int i = 0; i < _linkedList->get_count(); i++){
		int number = _linkedList->GetValue(i);
		hashMap->Put(number, GetFizzBuzz(number));
	}
	cout << "  ...  Here is our HashMap:" << endl;
	std::string map;
	for (int i = 0; i < _linkedList->get_count(); i++){
		int key = _linkedList->GetValue(i);
		map += std::to_string(key) + " " + hashMap->GetElement(key) + "\n";
	}
	cout << map << endl;
	return *hashMap;
}

void RemoveElementFromHashMap(HashMap *_hashMap){
	cout << "Hmmm...on second thought, it may be a little too big.  I am going to remove one of the elements.  Which one do you want me to get rid of?" << endl;
	int key;
	cin >> key;
	cout << endl;
	while (!_hashMap->Contains(key)){
		cout << "Just give me the key, and I will remove the entire element." << endl;
		cin >> key;
		cout << endl;
	}
	_hashMap->Remove(key);
	cout << "Now that's what I call a strong defense against evil!  " << _hashMap->get_count() << " elements is the perfect size!" << endl;
}

void EndGame(){
	cout << endl << "Thank you so much for your help!  You are a true hero!" << endl;
}