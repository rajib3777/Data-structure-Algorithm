#include<bits/stdc++.h>
using namespace std;
void sorted_unique(vector<int>& A)
{
    set<int> s(A.begin(),A.end());

    for(int val : s)
    {
        cout << val << " ";
    }
    cout << endl;
}



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

        sorted_unique(A);
    
    }


    return 0;
}