//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <fstream>
//using namespace std;
//
//struct Node {
//
//    int data;
//    Node* next;
//    Node* prev;
//    Node* prevEvenOdd;
//    Node* nextEvenOdd;
//
//};
//
//void nodeInsetail(Node** head,
//    Node** tail,
//    int key, fstream& ErrorFile)
//{
//
//    Node* p = new Node();
//    p->data = key;
//    p->next = NULL;
//    p->prev = NULL;
//
//
//    if ((*head) == NULL)
//    {
//        (*head) = p;
//        (*tail) = p;
//        return;
//    }
//
//    if ((p->data) > ((*tail)->data))
//    {
//        p->prev = (*tail);
//        (*tail)->next = p;
//        (*tail) = p;
//        return;
//    }
//
//    if ((p->data) < ((*head)->data))
//    {
//        (*head)->prev = p;
//        p->next = (*head);
//        (*head) = p;
//        return;
//    }
//
//    if ((p->data) == ((*head)->data))
//    {
//        ErrorFile << "The number you are trying to add is alr in the list" << endl;
//    }
//
//
//    Node* temp = (*head)->next;
//    while ((temp->data) < (p->data)) 
//        temp = temp->next;
//
//
//    (temp->prev)->next = p;
//    p->prev = temp->prev;
//    temp->prev = p;
//    p->next = temp;
//
//    if (key % 2 == 0) {
//     
//     Node* evenlist = p->nextEvenOdd; //trying to compare what is in even list already to our new value - we get new value by 
//        //tranversing through list to get evens
//      
//      while (((evenlist->data) % 2 == 0) && (evenlist->next) != nullptr) {
//          evenlist = evenlist->nextEvenOdd;
//    
//          (p->prevEvenOdd)->nextEvenOdd = p;
//
//    //        (temp->prev)->next = s;
//    //        s->prev = temp->prev;
//    //        temp->prev = s;
//    //        s->next = temp;
//    //    }
//    //}
//    //else
//    //{
//    //    Node* oddlist = p;
//    //    while (!((p->data) % 2 == 0 && (oddlist->next) != nullptr)) {
//    //        oddlist = oddlist->next;
//        }
//    }
//}
//
//void PrintListBackward(Node* temp) {
//    while (temp != NULL && temp->next != NULL) {
//        temp = temp->next;
//    }
//    cout << "Here are all values backwards:" << endl;
//    while (temp) {
//        cout << temp->data << endl;
//        temp = temp->prev;
//    }
//}
// 
//void printList(Node * temp, char C)
//    {
//        char a = 'A'; //char nonsense is to give user an option to print the list in Ascending or Descending order
//        char d = 'D';
//        if (C == 'A') {
//            cout << "Here are all values:" << endl;
//            while (temp != NULL) {
//                cout << temp->data << endl;
//                temp = temp->next;
//            }
//        }
//        if (C == 'D') {
//            PrintListBackward(temp);
//        }
//    }
//
//
//int main() {
//
//    Node* left = NULL;
//    Node* right = NULL;
//
//
//    cout << "Hello and Welcome to IDEK what this is!" << endl << "Your list is curr empty" << endl;
//
//    fstream ErrorFile; //obj of fstream for error log 
//    ErrorFile.open("errorlog.txt");
//    // if (!ErrorFile.is_open()) cout << "hello dummy";
//
//    fstream IntegerFile; //obj of fsteam for integer numbers
//    IntegerFile.open("integer.dat");
//    if (IntegerFile.good() == false) {
//        cout << strerror(errno);
//        ErrorFile << "Error" << endl;
//    }
//
//    int x;
//    while (IntegerFile >> x) //this while loop will execute till .eof() but I like this cause its specfically looking for ints
//    {
//        if (x < 1) // just supposed to write out error not stop the code 
//        {
//            ErrorFile << "You put a fraction... Program will execute\n" << endl;
//            cout << "<1" << endl;
//            break;
//        }
//        if (x < 0)
//        {
//            ErrorFile << "Ints should be greater than 0...Program is ending\n" << endl;
//            cout << "<0" << endl;
//            break;
//        }
//        nodeInsetail(&left, &right, x, ErrorFile);
//    }
//
//    //menu
//    printList(left, 'A');
//    printList(left, 'D');
//
//    IntegerFile.close();
//    ErrorFile.close();
//}