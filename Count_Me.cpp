#include<bits/stdc++.h>
using namespace std;
void get__max_count(map<string,int>& mp,string S)
{
    stringstream ss(S);
    string word;

    string target_word;
    int count = 0;

    while (ss >> word)
    {
        mp[word]++;

        if(mp[word] > count)
        {
            count = mp[word];
            target_word = word;
        }
            
    }

    cout << target_word << " " << count << endl;
}


int main()
{
    int T;
    cin >> T;

    cin.ignore();
    while(T--)
    {
        string S;
        getline(cin,S);

        map<string,int> mp;

        get__max_count(mp,S);
        
    }


    return 0;
}