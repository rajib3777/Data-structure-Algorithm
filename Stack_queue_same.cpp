#include<bits/stdc++.h>
using namespace std;

bool are_same(stack<int> S,queue<int> Q)
{
    while(!S.empty() && !Q.empty())
    {
        if(S.top() != Q.front())
        {
            return false;
        }
        S.pop();
        Q.pop();
    }
    return S.empty() && Q.empty();
}
    
int main()
{
    stack<int> S;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int X;
        cin >> X;
        S.push(X);
    }

    queue<int> Q;

    int m;
    cin >> m;

    for(int i = 0; i < n; i++)
    {
        int X;
        cin >> X;
        Q.push(X);
    }


    if(are_same(S,Q))
    {
        cout << "This Stack are same" << endl;

        cout << "Outputs are given below" << endl;
        while(!S.empty())
        {
            cout << S.top() << " ";
            S.pop();
        }

        cout << endl;

        while(!Q.empty())
        {
            cout << Q.front() << " ";
            Q.pop();
        }
    }
    else
    {
        cout << "This Stack are not same" << endl;
    }


    return 0;
}