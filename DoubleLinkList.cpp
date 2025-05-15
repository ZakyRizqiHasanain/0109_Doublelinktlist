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

        // Step 1: Allocate memory for new node
        node *newnode = new node();

        
    }
};