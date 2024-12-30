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
        this -> next = nullptr;
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

void search_kth_node(Node* head,int idx)
{
    Node* temp = head;
    Node* temp2 = head;

    for(int i = 0;i < idx; i++)
    {
        if(temp == nullptr)
        {
            return;
        }

        temp = temp->next;
    }

    while(temp != nullptr)
    {
        temp = temp->next;
        temp2 = temp2->next;
    }
    
    if(temp2 != nullptr)
    {
        cout << temp2->val << endl;
    }
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

    search_kth_node(head,3);

    return 0;
}