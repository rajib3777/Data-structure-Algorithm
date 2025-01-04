#include<bits/stdc++.h>
using namespace std;
class Node
{
    public :
    int V;
    Node* next;

    Node(int V)
    {
        this -> V = V;
        this -> next = NULL;
    }
};

void insert_at_head(Node* &head,Node* &tail,int V)
{
    Node* newnode = new Node(V);
    newnode->next = head;
    head = newnode;

    if(tail == NULL)
    {
        tail = head;
    }

}

void delete_at_pos(Node* &head,Node* &tail,int pos)
{
    if(head == NULL || pos < 0)
    {
        return;
    }
    if(pos == 0)
    {
        Node* deletenode = head;
        head = head->next;
        if(head == NULL)
        {
            tail = NULL;
        }
        delete deletenode;
        return;
    }
    
    Node* temp = head;

    for(int i = 0;temp != NULL && i < pos - 1;i++)
    {
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL)
    {
        return;
    }
    Node* deletenode = temp->next;
        temp->next = temp->next->next;
        if(temp->next == NULL)
        {
            tail = temp;
        }
        delete deletenode;
    
}

void insert_at_tail(Node* &head,Node* &tail,int V)
{
    Node* newnode = new Node(V);
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
    Node* temp =head;

    while(temp != NULL)
    {
        cout << temp->V << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main()
{
    int Q;
    cin >> Q;

    Node* head = NULL;
    Node* tail = NULL;

    
    while(Q--)
    {

        int X,V;
        cin >> X >> V;

        if(X == 0)
        {
            insert_at_head(head,tail,V);
        }
        else if(X == 1)
        {
            insert_at_tail(head,tail,V);
        }
        else if(X == 2)
        {
            delete_at_pos(head,tail,V);
        }

        print_liked_list(head);

    }


    return 0;
}