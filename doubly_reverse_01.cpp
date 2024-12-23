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

void print_linked_list(Node* head)
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
    list<int> l;

    int val;
    while (true)
    {
        cin >> val;
        if(val == -1)
        {
            break ;
        }
        l.push_back(val);
    }

    l.reverse();

    Node* head = NULL;
    Node* tail = NULL;

    for(int val : l)
    {
        insert_it_tail(head,tail,val);
    }


    print_linked_list(head);
    


    return 0;
}