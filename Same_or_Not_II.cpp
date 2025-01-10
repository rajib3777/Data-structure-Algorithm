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


class mystack
{
    
    public :

    Node* head = NULL;
    Node* tail = NULL;

    void push(int Values)
    {
        Node* newnode = new Node(Values);
        if(head == NULL)
        {
            head = newnode;
            tail = newnode;
            return;
        }

        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;

    }

    void pop()
    {
        Node* deletenode = tail;
        tail = tail->prev;
        delete deletenode;
        if(tail == NULL)
        {
            head = NULL;
            return;
        }
        tail->next = NULL;
    }

    int top()
    {
        return tail->val;
    }

    bool empty()
    {
        return head == NULL;
    }
};

class myqueue
{
    public :

    Node* head = NULL;
    Node* tail = NULL;

    void push(int Values)
    {
        Node* newnode = new Node(Values);
        if(head == NULL)
        {
            head = newnode;
            tail = newnode;
            return;
        }

        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }

    void pop()
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

    int front()
    {
        return head->val;
    }

    bool empty()
    {
        return head == NULL;
    }
};
bool are_same(mystack &st,myqueue &qu)
{
    while(!st.empty() && !qu.empty())
    {
        if(st.top() != qu.front())
        {
            return false;
        }
        st.pop();
        qu.pop();
    }
    return st.empty() && qu.empty();
}


int main()
{
    mystack st;

    int N,M;
    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        int Values;
        cin >> Values;
        st.push(Values);
    }

    myqueue qu;

    for(int i = 0; i < M; i++)
    {
        int Values;
        cin >> Values;
        qu.push(Values);
    }

    if(are_same(st,qu))
    {
        cout << "YES" << endl;

    }
    else
    {
        cout << "NO" << endl;
    }


    return 0;
}