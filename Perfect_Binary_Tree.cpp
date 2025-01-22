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

int height_tree(tree* root)
{
    if(root == NULL)
      return 0;

    int l = height_tree(root->left);
    int r = height_tree(root->right);

    return 1 + max(l,r);

}


int count_node(tree* root)
{
    if(root == NULL)
      return 0;

    int l = count_node(root->left);
    int r = count_node(root->right);

    return l + r + 1;
}


int power_of(int height)
{
    if(height == 0)
      return 1;

    return 2 * power_of(height - 1);
}


int main()
{
    tree* root = NULL;

    root = input_tree(root);

    int height = height_tree(root);

    int x = power_of(height) - 1;

    int y = count_node(root);

    if(x == y)
       cout << "YES" << endl;

    else
       cout << "NO" << endl;

    return 0;
}