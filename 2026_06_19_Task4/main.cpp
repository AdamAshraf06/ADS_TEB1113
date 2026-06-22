#include <iostream>
#include <string>

using namespace std;


struct Node {
    string data;
    Node* next;
};


int main() {

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

}