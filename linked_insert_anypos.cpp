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

void insert_any_pos(Node* &head,int pos,int val)
{
    Node* newnode = new Node(val);
    Node* temp = head;

    for(int i = 0;i < pos - 1;i++)
    {
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;

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

    Node* pos = d;

    insert_any_pos(head,3,9);
    //(head,tail,1008900);
    //insert_at_tail(head,tail,3200);



    print_head(head);



    return 0;
}