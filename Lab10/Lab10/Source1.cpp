#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

struct Node {

    int data;
    Node* next;
    Node* prev;
    Node* prevEvenOdd;
    Node* nextEvenOdd;

};


void nodes(Node** head,
    Node** tail,
    int key, fstream& ErrorFile)
{

    Node* s = new Node();
    s->data = key;
    s->next = NULL;


    if ((*head) == NULL)
    {
        (*head) = s;
        (*tail) = s;
        (*head)->prev = NULL;
        return;
    }



    if ((s->data) == ((*head)->data))
    {
        ErrorFile << "The number you are trying to add is alr in the list" << endl;
    }

    if (s->data < (*head)->data) {
        s->prev = NULL;
        (*head)->prev = s;
        s->next = (*head);
        (*head) = s;
        return;
    }


    if ((s->data) > ((*tail)->data))
    {
        s->prev = (*tail);
        (*tail)->next = s;
        (*tail) = s;
        return;
    }


    Node* temp = (*head)->next;
    while ((temp->data) < (s->data))
        temp = temp->next;


    (temp->prev)->next = s;
    s->prev = temp->prev;
    temp->prev = s;
    s->next = temp;
}

void PrintListBackward(Node* temp) {
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }
    cout << "Here are all values backwards:" << endl;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
}

void printList(Node* temp, char C)
{
    char a = 'A'; //char nonsense is to give user an option to print the list in Ascending or Descending order
    char d = 'D';
    if (C == 'A') {
        cout << "Here are all values:" << endl;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    if (C == 'D') {
        PrintListBackward(temp);
    }
}

void printOdd(Node* temp) {
    while (temp != NULL) {
        if (temp->data % 2 != 0) {
            cout << temp->data << " ";

        }
        temp = temp->next;
    }
}

void printEven(Node* temp) {
    while (temp != NULL && temp->data % 2 == 0) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {

    Node* left = NULL;
    Node* right = NULL;

    cout << "Welcome" << endl << "--------" << endl;

    fstream ErrorFile; //obj of fstream for error log 
    ErrorFile.open("errorlog.txt");
    // if (!ErrorFile.is_open()) cout << "hello dummy";

    fstream IntegerFile; //obj of fsteam for integer numbers
    IntegerFile.open("integer.dat");
    if (IntegerFile.good() == false) {
        cout << strerror(errno);
        ErrorFile << "Error" << endl;
    }

    int x;
    while (IntegerFile >> x) //this while loop will execute till .eof() but I like this cause its specfically looking for ints
    {
        if (x < 1) // just supposed to write out error not stop the code 
        {
            ErrorFile << "Ints should be greater than 1... Program will execute\n" << endl;
            cout << "<1" << endl;
            break;
        }
        if (x < 0)
        {
            ErrorFile << "Ints should be greater than 0...Program is ending\n" << endl;
            cout << "<0" << endl;
            break;
        }
        nodes(&left, &right, x, ErrorFile);
    }
    printList(left, 'A');
    cout << endl << endl;
    printList(left, 'D');
    cout << endl;
    cout << endl;

    cout << "The Even values:" << endl;
    printEven(left);

    cout << endl;
    cout << endl;

    cout << "The odd values:" << endl;

    printOdd(left);

    IntegerFile.close();
    ErrorFile.close();
}