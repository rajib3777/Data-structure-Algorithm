#include<bits/stdc++.h>
using namespace std;
class Node
{
    public :
    string val;
    Node* next;
    Node* prev;

    Node(string val)
    {
        this -> val = val;
        this -> next = NULL;
        this -> prev = NULL;
    }
};


void insert_it_tail(Node* &head,Node* &tail,string val)
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

Node* visit_link(Node* head,string address)
{
    Node* temp = head;

    while(temp != NULL)
    {
        if(temp->val == address)
        {
            return temp;
        }

        temp = temp->next;
    }
    return NULL;   
}

void get_target(Node* &head,Node* &cur,int Q)
{
    string input,target;

    for(int i = 0; i < Q ; i++)
    {
        cin >> input;

        if(input == "visit")
        {
            cin >> target;

            Node* get_it = visit_link(head,target);
            if(get_it != NULL)
            {
                cur = get_it;
                cout << cur->val << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }

        }

        else if(input == "prev")
        {
            if(cur != NULL && cur->prev != NULL)
            {
                cur = cur->prev;
                cout << cur->val << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }

        }

        else if(input == "next")
        {
            if(cur != NULL && cur->next != NULL)
            {
                cur = cur->next;
                cout << cur->val << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }

        }
    }
}


int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    string address;

    while(cin >> address && address != "end")
    {
        insert_it_tail(head,tail,address);
    }

    int Q;
    cin >> Q;
    Node* pres = head;

    get_target(head,pres,Q);


    return 0;
}