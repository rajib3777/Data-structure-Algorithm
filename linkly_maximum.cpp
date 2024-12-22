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


int max_at_linkly(Node* head)
{
    if(head == NULL)
    {
        cout << "The link list is empty" << endl;
        return INT_MIN;
    }

    int max_val = head->val;

    Node* temp = head->next;

    while(temp != NULL)
    {
        if(temp->val > max_val)
        {
            max_val = temp->val;
        }

        temp = temp->next;
    }

    return max_val;

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

    int max = max_at_linkly(head);

    cout << max << endl;

    return 0;
}