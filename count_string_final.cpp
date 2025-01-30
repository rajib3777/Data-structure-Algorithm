#include<bits/stdc++.h>
using namespace std;

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
            else if(mp[word] == count)
            {
                if(target_word.empty() || target_word > word)
                {
                    target_word = word;
                }
            }
        }

        cout << target_word << " " << count << endl;
    }


    return 0;
}