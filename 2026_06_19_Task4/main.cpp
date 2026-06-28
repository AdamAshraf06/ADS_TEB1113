#include <iostream>
#include <math.h>
#include <string>

using namespace std;

struct Node {
    string name;
    Node* next;
};

Node* head = nullptr;
// DOUBLE LINK LIST-----------------------------------------------------------------------------------------------
// Insert  First--------------------------------------------------------------------------------------------------
void insertFirstC(string value) {

    Node* newNode = new Node();
    newNode->name = value;

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;

    // go to last node
    while (temp->next != head) {
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

//Insert Last----------------------------------------------------------------------------------------------------------
void insertLastC(string value) {

    Node* newNode = new Node();
    newNode->name = value;

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}
//Insert Nth-Position---------------------------------------------------------------------------------------------------
void insertNthC(string value, int pos) {

    if (pos == 1) {
        insertFirstC(value);
        return;
    }

    Node* newNode = new Node();
    newNode->name = value;

    Node* temp = head;

    for (int i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}
//Delete First---------------------------------------------------------------------------------------------------------
void deleteFirstC() {

    if (head == nullptr) {
        cout << "List is empty";
        return;
    }

    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    Node* last = head;

    while (last->next != head) {
        last = last->next;
    }

    Node* temp = head;
    head = head->next;
    last->next = head;

    delete temp;
}
//Delete Last-----------------------------------------------------------------------------------------------------------
void deleteLastC() {

    if (head == nullptr) {
        cout << "List is empty";
        return;
    }

    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    Node* current = head;

    while (current->next->next != head) {
        current = current->next;
    }

    Node* temp = current->next;
    current->next = head;
    delete temp;
}
//Delete Nth-Position---------------------------------------------------------------------------------------------------
void deleteNthC(int pos) {

    if (head == nullptr) {
        cout << "List is empty";
        return;
    }

    if (pos == 1) {
        deleteFirstC();
        return;
    }

    Node* current = head;

    for (int i = 1; i < pos - 1 && current->next != head; i++) {
        current = current->next;
    }

    Node* temp = current->next;

    if (temp == head) {
        cout << "Invalid position";
        return;
    }

    current->next = temp->next;
    delete temp;
}
//display-Circular------------------------------------------------------------------------------------------------------
void displayC() {

    if (head == nullptr) {
        cout << "List is empty";
        return;
    }

    Node* current = head;

    do {
        cout << current->name << " -> ";
        current = current->next;
    } while (current != head);

    cout << "(back to head)";
}

//DOUBLE LINKED LIST---------------------------------------------------------------------------------------------------
struct node {
    string name;
    node* prev;
    node* next;
};

node* Head = nullptr;

//Insert First---------------------------------------------------------------------------------------------------------
void insertFirstD(string value) {

    node* newNode = new node();

    newNode->name = value;
    newNode->prev = nullptr;
    newNode->next = Head;

    if (Head != nullptr) {
        Head->prev = newNode;
    }

    Head = newNode;
}
//Insert Last----------------------------------------------------------------------------------------------------------
void insertLastD(string value) {

    node* newNode = new node();

    newNode->name = value;
    newNode->next = nullptr;

    // Empty list
    if (Head == nullptr) {
        newNode->prev = nullptr;
        Head = newNode;
        return;
    }

    node* current = Head;

    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
}

//Insert Nth-Position---------------------------------------------------------------------------------------------------
void insertNthD(string value, int position) {

    if (position == 1) {
        insertFirstD(value);
        return;
    }

    node* newNode = new node();
    newNode->name = value;

    node* current = Head;

    for (int i = 1; i < position - 1 && current != nullptr; i++) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Invalid Position";
        delete newNode;
        return;
    }

    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != nullptr) {
        current->next->prev = newNode;
    }

    current->next = newNode;
}

//Delete First---------------------------------------------------------------------------------------------------------
void deleteFirstD() {

    if (Head == nullptr) {
        cout << "List is empty";
        return;
    }

    node* temp = Head;

    Head = Head->next;

    if (Head != nullptr) {
        Head->prev = nullptr;
    }

    delete temp;
}
//Delete Last-----------------------------------------------------------------------------------------------------------
void deleteLastD() {

    if (Head == nullptr) {
        cout << "List is emptyn";
        return;
    }

    // Only one node
    if (Head->next == nullptr) {
        delete Head;
        Head = nullptr;
        return;
    }

    node* current = Head;

    while (current->next != nullptr) {
        current = current->next;
    }

    current->prev->next = nullptr;

    delete current;
}

//Delete Nth-Position--------------------------------------------------------------------------------------------------
void deleteNthD(int position) {

    if (Head == nullptr) {
        cout << "List is empty";
        return;
    }

    if (position == 1) {
        deleteFirstD();
        return;
    }

    node* current = Head;

    for (int i = 1; i < position && current != nullptr; i++) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Invalid Position";
        return;
    }

    current->prev->next = current->next;

    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }

    delete current;
}

//Display Double--------------------------------------------------------------------------------------------------------
void displayD() {

    if (Head == nullptr) {
        cout << "List is empty";
        return;
    }

    node* current = Head;

    while (current != nullptr) {
        cout << current->name << " <-> ";
        current = current->next;
    }

    cout << "NULL";
    cout << endl;
}
//Main Function=========================================================================================================
int main() {

    cout << "CIRCULAR LINKED LIST"<<endl;

    insertLastC("Aimar");
    insertLastC("Ahmad");
    insertLastC("Anjana");
    insertLastC("Jessy");

    cout << "Initial list:";
    displayC();

    insertFirstC("Adam");
    cout << "After insertFirst:";
    displayC();

    insertNthC("John", 3);
    cout << "After insertNth(3):";
    displayC();

    deleteFirstC();
    cout << "After deleteFirst:";
    displayC();

    deleteLastC();
    cout << "After deleteLast:";
    displayC();

    deleteNthC(2);
    cout << "After deleteNth(2):";
    displayC();

    cout<<endl;
    cout<<"================================================================================================="<<endl;

    cout<<"DOUBLE LNKED LIST"<<endl;

    insertLastD("Aimar");
    insertLastD("Ahmad");
    insertLastD("Anjana");
    insertLastD("Jessy");

    cout << "Original List:";
    displayD();

    insertFirstD("Adam");
    cout << "After insertFirst:";
    displayD();

    insertNthD("John", 3);
    cout << "After insertNth(3):";
    displayD();

    deleteFirstD();
    cout << "After deleteFirst:";
    displayD();

    deleteLastD();
    cout << "After deleteLast:";
    displayD();

    deleteNthD(2);
    cout << "After deleteNth(2):";
    displayD();
    return 0;
}
/*
    Node *node1 = new Node();
    Node *node2 = new Node();
    Node *node3 = new Node();

    node1-> data = "Aimar";
    node1->next = node2;

    node2-> data = "Ahmad";
    node2->next = node3;

    node3-> data = "Anjana";
    node3->next = nullptr;

    Node *temp = node1;

    while (temp != nullptr)
    {
        cout << temp-> data << " ";
        temp = temp->next;
    }

    delete node1;   //Delete to prevent data leak
    delete node2;
    delete node3;
}*/