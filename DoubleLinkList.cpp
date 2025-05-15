#include<iostream>
#include<string>
using namespace std;

class node
{
public:
    int noMhs;
    node *next;
    node *prev;
};

class Doublelinklist
{
private:
    node *start;

public:
    Doublelinklist()
    {
        start = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nEnter the roll number of the student: ";
        cin >> nim;

       
    }
};