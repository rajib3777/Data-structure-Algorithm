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

void sort_link_list(Node* head)
{
    for(Node* temp = head;temp->next != NULL ; temp = temp->next)
    {
        for(Node* i = temp->next ; i != NULL ; i = i->next)
        {
            if(temp->val < i->val)
            {
                swap(temp->val,i->val);
            }
        }
    }
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
    while(true)
    {
        cin >> val;
        if(val == -1)
        {
            break;
        }
        insert_at_tail(head,tail,val);

    }

    sort_link_list(head);

    print_liked_list(head);



    return 0;

}

