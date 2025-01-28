#include<bits/stdc++.h>
using namespace std;

void command_pannel(priority_queue<int,
                    vector<int>,greater<int>>& pq,
                    int command,int X)
{
    if(command == 0)
    {
        pq.push(X);
        cout << pq.top() << endl;
    }

    else if(command == 1)
    {
        if(!pq.empty())
        {
            cout << pq.top() << endl;
        }
        else
        {
            cout << "Empty" << endl;
        }
    }

    else if(command == 2)
    {
        if(pq.empty())
        {
           cout << "Empty" << endl;
        }
        else
        {
            pq.pop();

            if(pq.empty())
            {
               cout << "Empty" << endl;
            }
            else
            {
                cout << pq.top() << endl;
            }
        }
    }
}

void current_min(vector <int> &A,vector<pair<int,int>>& V)
{
    int N = A.size();

    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i = 0;i < N; i++)
    {
        pq.push(A[i]);
    }

    for(int i = 0 ; i < V.size() ; i++)
    {
        int command = V[i].first;
        int X = V[i].second;

        command_pannel(pq,command,X);
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

    current_min(A,V);



    return 0;
}