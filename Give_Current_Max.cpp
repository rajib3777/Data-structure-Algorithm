#include<bits/stdc++.h>
using namespace std;

class student
{
    public:
    string Name;
    int Roll;
    int Marks;

    student(string Name,int Roll,int Marks)
    {
        this->Name = Name;
        this->Roll = Roll;
        this->Marks = Marks;
    }

};

class cmp
{
    public :

    bool operator()(student l,student r)
    {
        if(l.Marks == r.Marks)
        {
           return l.Roll > r.Roll;
        }
        return l.Marks < r.Marks;

    }
};

int main()
{
    int N;
    cin >> N;

    priority_queue<student,vector<student>,cmp> pq;

    for(int i = 0;i < N;i++)
    {
        string Name;
        int Roll,Marks;
        cin >> Name >> Roll >> Marks;
        student obj(Name,Roll,Marks);
        pq.push(obj);
    }

    int Q;
    cin >> Q;

    for(int i = 0 ; i < Q ; i++)
    {
        int command;
        cin >> command;

        if(command == 0)
        {
            string Name;
            int Roll,Marks;
            cin >> Name >> Roll >> Marks;
            student obj(Name,Roll,Marks);
            pq.push(obj);
            student max = pq.top();
            cout << max.Name << " " << max.Roll << " " << max.Marks << endl;
        }
        
        else if(command == 1)
        {
            if(!pq.empty())
            {
                student max = pq.top();
                cout << max.Name << " " << max.Roll << " " << max.Marks << endl;
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
                    student max = pq.top();
                    cout << max.Name << " " << max.Roll << " " << max.Marks << endl;
                }
                else
                {
                    cout << "Empty" << endl;
                }
            }
        }
    }


    return 0;
}