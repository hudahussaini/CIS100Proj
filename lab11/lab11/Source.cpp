#include<iostream>
#include <fstream>

using namespace std;

struct node

{

	int data;

	node* next;

};

//making new node into temp node
node* Insert(int a)

{
	struct node* temp = new node;

	temp->data = a;
	temp->next = NULL;

	return temp;
}

node* AddToList(node* head, int data)

{

	struct node* newnode;
	newnode = Insert(data);

	if (head == NULL)

	{
		head = newnode;
		return head;
	}

	newnode->next = head;
	head = newnode;

	return head;

}

node* mergesort(node* h1, node* h2)

{

	node* t1 = new node;
	node* t2 = new node;
	node* temp = new node;

	if (h1 == NULL)

		return h2;

	if (h2 == NULL)

		return h1;

	t1 = h1;

	// Loops to add val from second list to first sorted.

	while (h2 != NULL)

	{
		t2 = h2;
		h2 = h2->next;

		t2->next = NULL;

		// data value < head in first list == adding node front.

		if (h1->data > t2->data)
		{
			t2->next = h1;
			h1 = t2;
			t1 = h1;

			continue;
		}

	flag:

			if (t1->next == NULL)

			{

				t1->next = t2;

				t1 = t1->next;

			}

			// Traverse first list until t2->data more than node's data.

			else if ((t1->next)->data <= t2->data)

			{

				t1 = t1->next;
				goto flag;

			}

			else

			{

				// Insert the node as t2->data is lesser than the next node.

				temp = t1->next;

				t1->next = t2;

				t2->next = temp;

			}
	}

	// Return the head of new sorted list.

	return h1;

}

// A function implementing Merge Sort on linked list using reference.

void MergeSort(node** head)

{

	node* first = new node;

	node* second = new node;

	node* temp = new node;

	first = *head;

	temp = *head;

	// Return if list have less than two nodes.

	if (first == NULL || first->next == NULL)

	{

		return;

	}

	else

	{

		// Break the list into two half as first and second as head of list.

		while (first->next != NULL)

		{

			first = first->next;

			if (first->next != NULL)

			{

				temp = temp->next;

				first = first->next;

			}

		}

		second = temp->next;

		temp->next = NULL;

		first = *head;

	}

	// Implementing divide and conquer approach.

	MergeSort(&first);

	MergeSort(&second);

	// Merge the two part of the list into a sorted one.

	*head = mergesort(first, second);

}

void display(node** head) {

	node* temp = new node;

	temp = *head;

	while (temp != NULL) {

		cout << temp->data << endl;

		temp = temp->next;

	}

}

int main()

{
	fstream infile;
	infile.open("input.txt");
	int n, i, num;

	struct node* head = new node;

	head = NULL;

	n = 21;

	if (!infile) {

		cout << "Cannot open input file.\n";

		return 1;

	}

	while (infile >> n) {

		head = AddToList(head, n);

	}

	cout << "Initial List: " << endl;

	display(&head);

	// Send reference of head into MergeSort().

	MergeSort(&head);

	// Printing the sorted data.

	cout << "\nSorted Data ";

	display(&head);

	infile.close();
	return 0;

}