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

void insert_at_head(Node* &head,int val)
{
    Node* newnode = new Node(val);
    newnode->next = head;
    head = newnode;
}

void print_head(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
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

    insert_at_head(head,900);
    insert_at_head(head,400);
    insert_at_head(head,700);
    insert_at_head(head,1000);
    insert_at_head(head,730);

    print_head(head);


    return 0;
}