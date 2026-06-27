#include <iostream>
#include <string>

using namespace std;

//Node Class Stack-----------------------------------------------------------------------------------------------------
class stack {
public:
        string name;
        stack* next;
};
stack* top = NULL;

//push stack
void push(string value) {
    stack* newStack = new stack();

    newStack->name = value;
    newStack->next = top;
    top=newStack;
}

//Pop Stack
void pop() {
    if (top == NULL) {
        cout << "Stack is Empty" << endl;
        return;
    }
    stack* temp = top;
    cout <<"Removed : "<< temp->name << endl;

    top = top->next;
    delete temp;
}

//Peek Stack
void peekStack() {
    if (top == NULL) {
        cout << "Stack is Empty" << endl;
    }
    else {
        cout << "Top Element : " <<top->name<< endl;
    }
}

//Display Stack
void displayStack() {
    stack* current = top;

    while (current != NULL) {
        cout << current->name << endl;
        current = current->next;
    }

    cout << endl;
}
//Node Class Queue-----------------------------------------------------------------------------------------------------
class queue {
public:
    string name;
    queue* next;
};
//Front & Rear Counter
queue* front= NULL;
queue* rear = NULL;

//Enqueue Queue
void enqueue(string value) {
    queue* newQueue = new queue();
    newQueue->name = value;
    newQueue->next = NULL;

    //If the queue empty,the value is become front & rear
    if (front == NULL && rear == NULL) {
        front =rear=newQueue;
    }
    //If the queue has elements,attach the value at the rear
    else {
        rear->next = newQueue;
        rear = newQueue;
    }
}

//Dequeue Queue
void dequeue() {
    if (front == NULL) {
        cout << "Queue Is Empty" << endl;
        return;
    }

    queue* temp = front;
    cout <<"Removed : "<< temp->name<<endl;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    delete temp;
}

//Peak Queue
void peekQueue() {
    if (front == NULL) {
        cout << "Queue is Empty" << endl;
    }
    else {
        cout << "Front Element : " <<front->name<< endl;
    }
}

//Display Queue
void displayQueue() {
    if (front == NULL) {
        cout << "Queue is Empty" << endl;
        return;
    }

    queue* current = front;

    while (current != NULL) {
        cout << current->name << endl;
        current = current->next;
    }

    cout << endl;
}

//---------------------------------------------------------------------------------------------------------------------
int main() {
    push("Danish");
    push("DamK");
    push("Ashraf");
    push("Baihaqi");

    cout<<"STACK"<<endl;
    cout<<"Current Stack : "<<endl;
    displayStack();

    peekStack();
    pop();
    cout << endl;

    cout<<"After Popped Stack : "<<endl;
    displayStack();

    peekStack();
    cout <<"-------------------------------------------------------------------------------------------------"<< endl;

    enqueue("Danish");
    enqueue("DamK");
    enqueue("Ashraf");
    enqueue("Baihaqi");

    cout<<"QUEUE"<<endl;
    cout<<"Current Queue : "<<endl;
    displayQueue();

    peekQueue();
    dequeue();
    cout << endl;

    cout<<"After Dequeued Queue : "<<endl;
    displayQueue();

    peekQueue();

    return 0;
}