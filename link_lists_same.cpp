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


int count_linked_list(Node* head)
{
    int count = 0;

    Node* temp = head;
    while(temp == NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}




int main()
{
    Node* head1 = NULL;
    Node* tail1 = NULL;
    Node* head2 = NULL;
    Node* tail2 = NULL;

    int val;
    while(true)
    {
        cin >> val;

        if(val == -1)
        {
            break;
        }
    }

    insert_at_tail(head1,tail1,val);


    while(true)
    {
        cin >> val;

        if(val == -1)
        {
            break;
        }
    }
    insert_at_tail(head2,tail2,val);



    int count1 = count_linked_list(head1);

    int count2 = count_linked_list(head2);


    if(count1 == count2)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }


    return 0;
}