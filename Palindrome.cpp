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


bool palindrome_check(Node* head,Node* tail)
{
    while(head != NULL && tail != NULL && head != tail && head->prev != tail)
    {
        if(head->val != tail->val)
        {
            return false;
        }
        head = head->next;
        tail = tail->prev;
    }

    return true;

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

    if(palindrome_check(head,tail))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    


    return 0;
}