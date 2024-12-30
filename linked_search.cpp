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

void insert_it_tail(Node* &head,Node* &tail,int val)
{
    Node* newnode = new Node(val);

    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

bool search_node(Node* head,int val)
{
    Node* temp = head;

    while(temp != NULL)
    {
        if(temp->val == val)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;


    int val;
    while(true)
    {
        cin >> val;
        if(val == -1)
        {
            break;
        }
        insert_it_tail(head,tail,val);

    }

    cin >> val;

    if(search_node(head,val))
    {
        cout << "found" << endl ;
    }
    else
    {
        cout << "Not found" << endl;
    }

    return 0;
}