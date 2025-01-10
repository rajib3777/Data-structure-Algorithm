#include<bits/stdc++.h>
using namespace std;
bool valid_check(stack<char> s,string S)
{
    for(char c : S)
    {
        if(c == '0')
        {
            if(!s.empty() && s.top() == '1')
            {
                s.pop();
            }
            else
            {
                s.push(c);
            }
        }

        if(c == '1')
        {
            if(!s.empty() && s.top() == '0')
            {
                s.pop();
            }
            else
            {
                s.push(c);
            }
        }
    }
    return s.empty();
}

int main()
{
    stack<char> s;

    int T;
    cin >> T;

    while(T--)
    {
        string S;
        cin >> S;

        if(valid_check(s,S))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

    }


    return 0;
}