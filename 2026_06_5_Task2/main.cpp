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

    //Save records of 5 students
/*
    A[0].id = 24001;
    A[0].name = "Adam";
    A[0].age = 18;
    A[0].course = "CS";


    A[1].id = 24002;
    A[1].name = "Amirul";
    A[1].age = 19;
    A[1].course = "CS";


    A[2].id = 24003;
    A[2].name = "Akmal";
    A[2].age = 18;
    A[2].course = "CS";


    A[3].id = 24004;
    A[3].name = "Hana";
    A[3].age = 20;
    A[3].course = "CS";


    A[4].id = 24005;
    A[4].name = "Becca";
    A[4].age = 18;
    A[4].course = "CS";

*/
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