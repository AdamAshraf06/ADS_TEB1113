#include <iostream>
#include <string>

using namespace std;

struct Node {
    string name;
    Node* next;
};

Node* head = nullptr;
// DOUBLE LINK LIST-----------------------------------------------------------------------------------------------
// Insert  First--------------------------------------------------------------------------------------------------
void insertFirst(string value) {

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
void insertLast(string value) {

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
void insertNth(string value, int pos) {

    if (pos == 1) {
        insertFirst(value);
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
void deleteFirst() {

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
void deleteLast() {

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
void deleteNth(int pos) {

    if (head == nullptr) {
        cout << "List is empty";
        return;
    }

    if (pos == 1) {
        deleteFirst();
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
void display() {

    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    Node* current = head;

    do {
        cout << current->name << " -> ";
        current = current->next;
    } while (current != head);

    cout << "(back to head)\n";
}


int main() {

    insertLast("Aimar");
    insertLast("Ahmad");
    insertLast("Anjana");
    insertLast("Jessy");

    cout << "Initial list:";
    display();

    insertFirst("Adam");
    cout << "After insertFirst:";
    display();

    insertNth("John", 3);
    cout << "After insertNth(3):";
    display();

    deleteFirst();
    cout << "After deleteFirst:";
    display();

    deleteLast();
    cout << "After deleteLast:";
    display();

    deleteNth(2);
    cout << "After deleteNth(2):";
    display();

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