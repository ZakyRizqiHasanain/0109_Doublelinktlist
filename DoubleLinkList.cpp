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

            // Step 6: newnode.prev = NULL
            newnode->prev = NULL;

            // Step 7: Start = newnode
            start = newnode;
            return;
        }
    
        // Insert in between node
        // Step 8: Locate position for insertion
        node *current = start;
        while (current->next != NULL && current->next->noMhs < nim)
        {
            current = current->next;
        }

        if (current->next != NULL && nim == current->next->noMhs)
        {
            cout << "\nDuplicate roll number not allowed" << endl;
            return;
        }

        //Step 9: Insert between current and current.next
        newnode->next = current->next; // Step 9a: newNode.next = current.next
        newnode->prev = current; // Step 9b: newNode.prev = current

        // Insert last node
        if (current->next != NULL)
            current->next->prev = newnode; // Step 9c: current.next.prev = newnode
        current->next = newnode; // Step 9d: current.next = newNode        
    }

    void hapus()
    {
        if (start == NULL)
        {
            cout << "\nLisy is empty" << endl;
            return;
        }
        
        cout << "Enter the NIM must be deleted: ";
        int rollno;
        cin >> rollno;

        node *current = start;
        // Step 1: tranverse the list to find the node
        while (current != NULL && current->noMhs != rollno)
        {
            current = current->next;
        }

        if (current == NULL)
        {
            cout << "Record not found" << endl;
            return;
        }

        // Step 2: If node is at the beginning
        if (current == start)
        {
            start = current->next; // Step 2a: start = start.next
            if (start != NULL)
            {
                start->prev = NULL; // Step 2b: start.prev = NULL
            }
        }
        else
        {
            // Step 3: Link previous node to next of current
            current->prev->next = current->next;

            //Step 4: if current is not the last node
            if (current->next != NULL)
                current->next->prev = current->prev;
        }

        // Step 5: Delete the node
        delete current;
        cout << "Record with roll number" << rollno << "deleted" << endl;
        
    }

    void tranverse()
    {
        if (start == NULL)
        {
            cout << "\nmList is empty" << endl;
            return;
        }

        // Step 1: Mark first node as currentnode
        node *currentnode = start;

        // Step 2: Repeat until currentnode == NULL
        cout << "\nRecords in ascending order of roll number are: \n";
        int i = 0;
        while (currentnode != NULL)
        {
            cout << i + 1 << ". " << currentnode->noMhs << " " << endl;

            //Step 3: Move to next node
            currentnode = currentnode->next;
            i++;
        }
    }
    void revtraverse()
    {
        if (start == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        //step 1: Move to last node
        node *currentnode = start;
        int i = 0;
        while (currentnode->next != NULL)
        {
            currentnode = currentnode->next;
            i++;
        }

        // step 2: traverse backward 
        cout << "\nRecord in descending order of roll number are: \n";
        while (currentnode != NULL)
        {
            cout << i + 1 << ". " << currentnode->noMhs << " " << endl;

            //Step 3: Move to previous node
            currentnode = currentnode->prev;
            i--;
        }
    }

    void searchdata()
    {
        if (start == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        int rollno;
        cout << "\nEnter the roll number to search: ";
        cin >> rollno;

        node *current = start;

        //Step 1:Traverse to find matching roll number
        while (current != NULL && current->noMhs != rollno)
            current = current->next;

        //Step 2: Output result
        if (current == NULL)
        {
            cout << "Record not found\n";
        }
        else
        {
            cout << "Record found\n";
            cout << "Roll number: " << current->noMhs << endl;
        }
    }
};

