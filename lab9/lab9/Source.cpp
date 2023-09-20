//Lab 9 - unsorted/Sorted Linked list Data Structure
// CPP file, author - Huda Husaini
//Update a record, Delete a record, List a record, list All tools, and Quit when finished.

struct record {
	int recordnum;
	string toolname;
	int Quantity;
	double cost;
	node* next;
};

main()
{
std::cout << "\n\Press one to update a record, 2 to delete a record, 3 to list a record, 4 to list all tools, 5 to add, or 0 to quit\n";
std::cin >> switchval;
switch (switchval) {
case 0:
	break;
case 1:
	updateData(recordFile);
case 2:
	deleteData(recordFile);
case 3:
	printRecord(recordFile);
case 4:
	printTools(recordFile);
case 5:
	adddata(recordFile);
}

void adddata(int num, node * *head, string tool, int Quant, double ct) {
	node* currptr,
		* insertItem = new node;
	for (int i = 0; i < 21; i++) {
		insert->toolname[i] = tool[i];
	}
	insertItem->toolname[i] = tool[i];
}
insertItem->toolname[20] = '\0';
insertIteam->Quanity = Quant;
insertItem->cost = ct;

if (*head == null) {
	insertItem->next = nullptr;
	*head = insertItem;
}
else if ((*head)->item > num) {
	insertItem->next = (*head);
	(*head) = insertItem;
}
else {
	currptr = *head;
	while (currPtr->next != Null && num > (currptr->next)->item) {
		currptr = currptr->next;

	}
	if (currPtr->next == Null) {
		insertItem->next = NULL;
		currptr->next = insertItem;
	}
	else {
		insertItem->next = currPtr->next;
	}

	if (currptr->next == NULL) {
		insertItem->next = NULL;
		currptr->next = insert Item;
	}
}

int main() {
	int option;
	node* myList = NULL;
	menu();
	//printlist
	InsertList(68, &myList, "Scredriver", 106, 6.99);
	//print
	InsertList(68, &myList, "Scredriver", 106, 6.99)
}

void update(int key, int value)       
{
	int flag = 0;
	if (start == NULL)
	{
		cout << "\nList is Empty!";
		exit(0);
	}


}