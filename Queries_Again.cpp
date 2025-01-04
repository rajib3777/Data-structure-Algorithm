#include <bits/stdc++.h>
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

void insert_at_idx(Node* &head,Node* &tail,int idx,int val)
{
    if(idx < 0)
    {
        cout << "Invalid" << endl;
        return;
    }
    
    Node* newnode = new Node(val);
    
    if(head == NULL && idx > 0)
    {
        cout << "Invalid" << endl;
        return;
    }
    
    if( idx == 0)
    {
        if(head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }
    
    else
    {
        Node* temp = head;
        for(int i = 0; temp != NULL && i < idx-1 ; i++)
        {
            temp = temp->next;
        }
        
        if(temp == NULL)
        {
            cout << "Invalid" << endl;
            return;
        }
        
        
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
        
        if(newnode->next != NULL)
        {
            newnode->next->prev = newnode;
        }
        
        else
        {
            tail = newnode;
        }
    }

    cout << "L ->";
    
    Node* temp = head;
    
    while(temp != NULL)
    {
        cout << " " << temp->val;
        temp = temp->next;
    }
    
    cout << endl;
    
    
    cout << "R ->" ;
    
    temp = tail;
    while(temp != NULL)
    {
        cout << " " << temp->val;
        temp = temp->prev;
    }
    
    cout << endl;
    
}

void delete_list(Node* head)
{
    while(head)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

}


int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    
    int Q ;
    cin >> Q;
    
    while(Q--)
    {
        int X,V;
        cin >> X >> V;
        
        insert_at_idx(head,tail,X,V);
    }
    
    delete_list(head);

    return 0;
}
