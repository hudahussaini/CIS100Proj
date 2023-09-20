//Lab 9 - unsorted Linked list Data Structure
//CPP file, author - Huda Husaini
//Update a record, Delete a record, List a record, list All tools, and Quit when finished.
#include <iostream>
using namespace std;

struct node {
	int recordnum;
	string toolname;
	int Quantity;
	double cost;
	node* next;
};

void PrintList(node* myList) {
	cout << "Here are all record numbers:" << endl;
	while (myList != NULL) {
		cout << myList->recordnum << endl;
		myList = myList->next;
	}
}
void PrintListBackward(node* myList) {
	while (myList != NULL && myList->next != NULL) {
		myList = myList->next;
	}
	cout << "Here are all values backwards:" << endl;
	while (myList) {
		cout << myList->letr << endl;
		myList = myList->prev;
	}
}
void  InsertList(char  item, node** head) {
	node* currPtr,
		* insertItem = new node;
	insertItem->letr = item;
	if (*head == NULL) {  //new list
		insertItem->prev = nullptr;
		insertItem->next = nullptr;
		*head = insertItem;
	}
	else if ((*head)->letr > item) { //new first item in list
		insertItem->prev = nullptr;
		insertItem->next = (*head);
		(*head)->prev = insertItem;
		*head = insertItem;
	}
	else {
		currPtr = *head;
		while (currPtr->next != NULL && item > (currPtr->next)->letr)
		{
			currPtr = currPtr->next;
		}
		//either we're at the end of list or before insertion point
		if (currPtr->next == NULL) { //end of list
			insertItem->next = NULL;
			insertItem->prev = currPtr;
			currPtr->next = insertItem;
		}
		else { //middle 
			of list
				insertItem->next = currPtr->next;
			insertItem->prev = currPtr;
			insertItem->next->prev = insertItem;
			currPtr->next = insertItem;
		}
	}
}
int main() {
	node* myList = NULL;
	cout << "List is empty\n";
	PrintList(myList);
	InsertList('g', &myList);
	PrintList(myList);
	InsertList('d', &myList);
	PrintList(myList);
	InsertList('r', &myList);
	PrintList(myList);
	InsertList('m', &myList);
	PrintList(myList);
	PrintListBackward(myList);
	cout << "\nFinished with lists\n";
	return -8; //just being different
}