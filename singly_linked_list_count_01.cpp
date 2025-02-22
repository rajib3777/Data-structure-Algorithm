#include<bits/stdc++.h>
using namespace std;

class Node
{
    public :
    int val;
    Node* next;

    Node(int val)
    {
        this -> val = val;
        this -> next = NULL;
    }
};


void insert_at_tail(Node* &head,Node* &tail,int val)
{
    Node* newnode = new Node(val);
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = tail->next;
    }
    
}


void print_liked_list(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->val << endl;
        temp = temp->next;
    }
    cout << endl;
}


int main()
{
    Node* head = NULL;
    Node* tail = NULL;


    int val;
    int count = 0;
    while(true)//o(N)
    {
        cin >> val;
        if(val == -1)
        {
            break;
        }
        insert_at_tail(head,tail,val);// o(1)

        count ++;

    }
    
    cout << count << endl;


    return 0;
}