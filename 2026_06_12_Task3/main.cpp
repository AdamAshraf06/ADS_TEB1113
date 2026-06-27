#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* next;
};

Node* head = NULL;

//Insert At Beginning--------------------------------------------------------------------------------------------------
void insertFirst(string value) {
    Node* newNode = new Node;
    newNode->name = value;

    newNode->next = head;

    head = newNode;
}
//Insert At End--------------------------------------------------------------------------------------------------------
void InsertEnd(string value) {
    Node* newNode = new Node;
    newNode->name = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

//Insert at NthPosition--------------------------------------------------------------------------------------------------
void insertNth(string value, int position) {

    if (position == 1) {
        insertFirst(value);
        return;
    }

    Node* newNode = new Node();
    newNode->name = value;

    Node* current = head;

    for (int i = 1; i < position - 1 && current != nullptr; i++) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Invalid Position!" << endl;
        delete newNode;
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

//Delete At Beginning---------------------------------------------------------------------------------------------------
void deleteFirst() {

    if (head == nullptr) {
        cout << "List is empty";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

//Delete At End--------------------------------------------------------------------------------------------------------
void deleteLast() {

    if (head == nullptr) {
        cout << "List is empty";
        return;
    }

    // Only one node
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* current = head;

    // Move to second last node
    while (current->next->next != nullptr) {
        current = current->next;
    }

    delete current->next;
    current->next = nullptr;
}

//Delete At NthPosition------------------------------------------------------------------------------------------------
void deleteNth(int position) {

    if (head == nullptr) {
        cout << "List is empty";
        return;
    }

    // Delete first node
    if (position == 1) {
        deleteFirst();
        return;
    }

    Node* current = head;

    // Move to node before target
    for (int i = 1; i < position - 1 && current != nullptr; i++) {
        current = current->next;
    }

    if (current == nullptr || current->next == nullptr) {
        cout << "Invalid position";
        return;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}
//Display--------------------------------------------------------------------------------------------------------------
void display() {
    Node* current = head;

    while (current != nullptr) {
        cout << current->name << " -> ";
        current = current->next;
    }

    cout << "NULL";
}
//---------------------------------------------------------------------------------------------------------------------

int main() {

    InsertEnd("Aimar");
    InsertEnd("Ahmad");
    InsertEnd("Anjana");
    InsertEnd("Jessy");

    cout << "Original List:";
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
    Node node1, node2, node3, node4;

    // Assign names
    node1.name = "Aimar";
    node2.name = "Ahmad";
    node3.name = "Anjana";
    node4.name = "Jessy";


    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = nullptr;


    Node* current = &node1;

    // Print node1
    cout << "Record 1: " << current->name << endl;

    current = current->next;
    cout << "Record 2: " << current->name << endl;

    current = current->next;
    cout << "Record 3: " << current->name << endl;

    current = current->next;
    cout << "Record 4: " << current->name << endl;


    current = current->next;
    if (current == nullptr) {

        cout << "End " << endl;
    }
*/
