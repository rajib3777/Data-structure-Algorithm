#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> st;

    int n;
    cin >> n;

    for(int i = 0; i < n ; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }

    cout << "size -> " << endl;

    cout << st.size() << endl;

    if(!st.empty())
       st.pop();

    
    cout << "output -> ";

    while(!st.empty())
    {
        cout << st.front() << " ";
        st.pop();
    }
    cout << endl;

    cout << "after output size -> " << endl;

    cout << st.size() << endl;

    return 0;
}