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

int sum_of_nodes(tree* root)
{
    if(root == NULL)
      return 0;

    if(root->left == NULL && root->right == NULL)
      return 0;

    return root->val + sum_of_nodes(root->left) + sum_of_nodes(root->right);

}

int main()
{
    tree* root = NULL;

    root = input_tree(root);

    int sum = sum_of_nodes(root);

    cout << sum << endl;



    return 0;
}