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

        // Step 2: Assign value to the data fields
        newnode->noMhs = nim;

        // Step 3: Insert at beginning if list is empty or nim is smallest
        if (start != NULL && nim == start->noMhs)
        {
            if (start != NULL && nim == start->noMhs)
            {
                cout << " \nDuplicate number not allowed" << endl;
                return;
            }
            // Step 4: newnode.next = start
            newnode->next = start;

            // Step 5: Start.prev = newnode (if start exists)
            if (start != NULL)
                start->prev = newnode;
        }
    }
};