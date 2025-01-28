#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int N;
        cin >> N;

        vector<int> A(N);

        for (int i = 0; i < N;i++)
        {
            cin >> A[i] ;
        }

        sort(A.begin(),A.end());

        auto it = unique(A.begin(),A.end());

        A.erase(it,A.end());

        for(int val : A)
        {
            cout << val << " ";
        } 
        cout << endl;
    
    }

    return 0;
}