#include<bits/stdc++.h>
using namespace std;
class mystack
{
    public :
    list<int> l;

    void push(int val)
    {
        l.push_back(val);
    }

    void pop()
    {
        l.pop_back();
    }

    int top()
    {
        return l.back();
    }

    bool empty()
    {
        return l.empty();
    }

};

bool are_same(mystack &Q,mystack &Q2)
{
    Q.l == Q2.l;
}


int main()
{
    mystack Q;
    mystack Q2;

    int N,M;

    cin >> N;

    for(int i = 0;i < N;i++)
    {
        int X;
        cin >> X;
        Q.push(X);
    }


    cin >> M;
    
    for(int i = 0;i < M;i++)
    {
        int Y;
        cin >> Y;
        Q2.push(Y);
    }


    if(are_same)
    {
        cout << "This Stack are same" << endl;

        cout << "Outputs are given below" << endl;

        while(!Q.empty())
        {
            cout << Q.top() << " ";
            Q.pop();
        }

        while(!Q2.empty())
        {
            cout << Q2.top() << " ";
            Q2.pop();
        }
    }

    else

    {
        cout << "This Stack are not same" << endl;
    }


    return 0;
}