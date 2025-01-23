#include<bits/stdc++.h>
using namespace std;
class student
{
    public :
    string S;
    int I;

    student(string S,int I)
    {
        this->S = S;
        this->I = I;
    }
};

class cmp
{
    public :

    bool operator()(student l,student r)
    {
        if(l.S == r.S)
        {
           return l.I < r.I;
        }
        return l.S >r.S;

    }
};
int main()
{
    int N;
    cin >> N;

    priority_queue<student,vector<student>,cmp> pq;

    for(int i = 0;i < N;i++)
    {
        string S;
        int I;
        cin >> S >> I;
        student obj(S,I);
        pq.push(obj);
    }

    while(!pq.empty())
    {
        cout << pq.top().S << " " << pq.top().I << " "  << endl;
        pq.pop();
    }




    return 0;
}