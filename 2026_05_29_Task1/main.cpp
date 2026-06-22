
#include <iostream>
#include <string>

using namespace std;

//Create a structure
struct Student{
    int id;
    string name;
    int age;
    string course;
};

int main() {
    //Declare an array
    Student A[5];

    for (int i = 0; i < 5; i++)
    {
        cout<<"Student"<<i+1<<endl;
        cout<<"-----------------------------"<<endl;
        cout << "Please Enter ID: ";
        cin >> A[i].id;
        cout << "Please Enter Name: ";
        cin >> A[i].name;
        cout << "Please Enter Age: ";
        cin >> A[i].age;
        cout << "Please Enter Course: ";
        cin >> A[i].course;
        cout << "----------------------------------------------------------------------------------------"<<endl;
    }

    //Display all records of 5 students
    for(int i = 0; i < 5; i++){
        cout<<"Student #"<<i+1<<" details:"<<endl;
        cout<<"Id :"<<A[i].id<<endl;
        cout<<"Name :"<<A[i].name<<endl;
        cout<<"Age :"<<A[i].age<<endl;
        cout<<"Course :"<<A[i].course<<endl;
        cout<<endl;
    }


    //Search student by id
    int searchId;
    cout<<"Enter student's id for search :";
    cin>>searchId;

    for(int i = 0; i < 5; i++){
        if(A[i].id == searchId){
            cout<<"Student #"<<i+1<<" details:"<<endl;
            cout<<"Id :"<<A[i].id<<endl;
            cout<<"Name :"<<A[i].name<<endl;
            cout<<"Age :"<<A[i].age<<endl;
            cout<<"Course :"<<A[i].course<<endl;
            cout<<endl;
        }
    }



}