#include<bits/stdc++.h>
using namespace std;
class Node
{
    public :
    int val;
    Node* next;
    Node* prev;

    Node(int val)
    {
        this -> val = val;
        this -> next = NULL;
        this -> prev = NULL;
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
    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;
}

void delete_at_head(Node* &head,Node* &tail)
{
    Node* deletenode = head;
    head = head->next;
    delete deletenode;
    if(head == NULL)
    {
        tail = NULL;
        return;
    }
    head->prev = NULL;
}

void print_liked_list(Node* head)
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
    Node* head = NULL;
    Node* tail = NULL;

    int val;
    while (true)
    {
        cin >> val;
        if(val == -1)
        {
            break ;
        }
        insert_it_tail(head,tail,val);
    }

    delete_at_head(head,tail);

    print_liked_list(head);

    return 0;
}