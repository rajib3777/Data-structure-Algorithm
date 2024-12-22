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

void print_head(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main()
{
    Node* head = new Node(10);    
    Node* a = new Node(100);    
    Node* b = new Node(200);    
    Node* c = new Node(300);    
    Node* d= new Node(400);

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;

    Node* tail = d;

    insert_at_tail(head,tail,200);
    insert_at_tail(head,tail,1008900);
    insert_at_tail(head,tail,3200);



    print_head(head);


    return 0;
}