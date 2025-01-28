#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<int> S;
    map<int,int> mp;

    int N;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        int X;
        cin >> X;
        S.insert(X);
        mp[X]++;
    }

    int Q;
    cin >> Q;

    for(int i = 0 ; i < Q ; i++)
    {
        int command;
        cin >> command;

        if(command == 0)
        {
            int X;
            cin >> X;
            S.insert(X);
            mp[X]++;
            cout << *S.begin() << endl;
        }
        
        else if(command == 1)
        {
            if(!S.empty())
            {
                cout << *S.begin() << endl;
            }

            else
            {
                cout << "Empty" << endl; 
            }
               
        }

        else if(command == 2)
        {
            if(!S.empty())
            {
                int min = *S.begin();
                mp[min]--;

                if(mp[min] == 0)
                {
                    S.erase(min);
                }

                if(!S.empty())
                {
                    cout << *S.begin() << endl;
                }

                else
                {
                    cout << "Empty" << endl;
                }
            }
        }

        else
        {
            cout << "Empty" << endl;
        }
    }


    return 0;
}



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



#include<bits/stdc++.h>
using namespace std;

void current_min()
{
    int Q;
    cin >> Q;

    int N;
    cin >> N;

    vector <int> A(N);

    for(int i = 0; i < N;i++)
    {
        cin >> A[i]; 
    }

    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i = 0; i < N;i++)
    {
        pq.push(A[i]); 
    }

    for(int i = 0; i < Q; i++)
    {
        int command;
        cin >> command;

        if(command == 0)
        {
            int X;
            cin >> X;

            pq.push(X);
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
            if(!pq.empty())
            {
                pq.pop();
                if(!pq.empty())
                {
                    cout << pq.top() << endl;
                }

                else
                {
                    cout << "Empty" << endl;
                }
            }

            else
            {
                cout << "Empty" << endl;
            }
        }
    }
}

int main()
{

    current_min();

    return 0;
}



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

        command = V[i].first;
        
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