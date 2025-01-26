#include<bits/stdc++.h>
using namespace std;

void current_min(vector<int>& A,vector<pair<int,int>>& V)
{
    int Q;
    cin >> Q;

    for(int i = 0;i < Q ; i++)
    {
        int command;
        cin >> command;

        if(command == 0)
        {
            int X;
            cin >> X;
            V.push_back({command,X});
        }
        else
        {
            V.push_back({command,0});
        }
    }

    for(int i = 0;i < V.size(); i++)
    {
        int command = V[i].first;
        
        if(command == 0)
        {
            int X = V[i].second;
            
            A.push_back(X);
            sort(A.begin(),A.end());
            cout << A[0] << endl;
        }


        else if(command == 1)
        {
            if(!A.empty())
            {
                sort(A.begin(),A.end());

                cout << A[0] << endl;
            }
            else
            {
                cout << "Empty" << endl;
            }
        }

        else if(command == 2)
        {
            if(!A.empty())
            {
                A.erase(A.begin());
                if(!A.empty())
                {
                   cout << A[0] << endl;
                }
                else
                {
                    cout << "Empty" << endl;
                }
            }
        }
    }
}

int main()
{
    int N;
    cin >> N;

    vector <int> A(N);

    for(int i = 0; i < N;i++)
    {
        cin >> A[i]; 
    }

    vector<pair<int,int>> V;

    current_min(A,V);



    return 0;
}