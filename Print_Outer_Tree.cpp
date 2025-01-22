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

void left_outter_tree(tree* root,bool isroot)
{
    if(root->left)
    {
        left_outter_tree(root->left,false);
    }
    else if(root->right)
    {
        left_outter_tree(root->right,false);
    }

    if(!isroot)
      cout << root->val << " ";
}

void right_outter_tree(tree* root)
{
    cout << root->val << " ";

    if(root->right)
    {
        right_outter_tree(root->right);
    }
    else if(root->right)
    {
        right_outter_tree(root->left);
    }

}


int main()
{
    tree* root = NULL;

    root = input_tree(root);

    left_outter_tree(root,true);
    right_outter_tree(root);


    return 0;
}