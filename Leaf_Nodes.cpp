#include<bits/stdc++.h>
using namespace std;
class tree
{
    public :
    int val;
    tree* left;
    tree* right;

    tree(int val)
    {
        this -> val = val;
        this -> left = NULL;
        this -> right = NULL;
    }
};

tree* input_tree(tree* root)
{
    int val;
    cin >> val;

    if(val == -1)
       root = NULL;
    else
    {
        root = new tree(val);
        queue<tree*> t;

        if(root)
          t.push(root);
        
        while(!t.empty())
        {
            tree* p = t.front();
            t.pop();

            int l,r;
            cin >> l >> r;
            tree *myleft,*myright;

            if(l == -1)
               myleft = NULL;
            else
               myleft = new tree(l);

            if(r == -1)
               myright = NULL;
            else
               myright = new tree(r);

            p->left = myleft;
            p->right = myright;

            if(p->left)
               t.push(p->left);
            if(p->right)
               t.push(p->right);
        }
    }
    return root;
}

void descending_order(tree* root,vector<int> &v)
{
    queue<tree*> t;
    t.push(root);
    if(root == NULL)
       return;
    
    while(!t.empty())
    {
        tree* p = t.front();
        t.pop();

        
        if(p->left == NULL && p->right == NULL)
           v.push_back(p->val);

        if(p->left)
           t.push(p->left);
        if(p->right)
           t.push(p->right);
    }
}

int main()
{
    tree* root = NULL;
    vector<int> v;

    root = input_tree(root);

    descending_order(root,v);

    sort(v.begin(),v.end(),greater<int>());

    for(int val : v)
    {
        cout << val << " ";
    }


    return 0;
}