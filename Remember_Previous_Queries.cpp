#include<bits/stdc++.h>
using namespace std;

void insert_at_head(list<int> &l,int V)
{
    l.push_front(V);
}

void insert_at_tail(list<int> &l,int V)
{
    l.push_back(V);
}

void delete_at_pos(list<int> &l,int pos)
{
    if(l.empty() || pos < 0 || pos >= l.size())
    {
        return;
    }
    auto it = l.begin();

    for(int i = 0; i < pos ; ++i)
    {
        ++it;
    }
    l.erase(it);
}

void print_liked_list(list<int> &l)
{
    if(l.empty())
    {
        cout << "L -> " << endl;
        cout << "R -> " << endl;
        return;
    }

    cout << "L -> ";
    for(int val : l)
    {
        cout << val << " " ;
    }

    cout << endl;
    l.reverse();

    cout << "R -> ";
    for(int val : l)
    {
        cout << val << " " ;
    }
    cout << endl;

    l.reverse();
}

int main()
{
    int Q;
    cin >> Q;

    list<int> l;

    while(Q--)
    {
        int X,V;
        cin >> X >> V;

        if(X == 0)
        {
            insert_at_head(l,V);
        }
        else if(X == 1)
        {
            insert_at_tail(l,V);
        }
        else if(X == 2)
        {
            delete_at_pos(l,V);
        }
        print_liked_list(l);
    }



    return 0;
}