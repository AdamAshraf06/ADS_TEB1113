#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* next;
};

int main() {

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

    return 0;
}