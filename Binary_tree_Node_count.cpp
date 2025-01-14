#include<bits/stdc++.h>
using namespace std;
class mytree
{
    public :
    int val;
    mytree* left;
    mytree* right;

    mytree(int val)
    {
        this -> val = val;
        this -> left = NULL;
        this -> right = NULL;
    }
};

mytree* input_tree(mytree* root)
{
    int val;
    cin >> val;

    if(val == -1)
    {
       root = NULL;
       return NULL;
    }
    else
    {
        root = new mytree(val);
        queue<mytree*> t;

        if(root)
          t.push(root);

        while(!t.empty())
        {
            mytree* p = t.front();
            t.pop();

            int l,r;
            cin >> l >> r;
            mytree *left,*right;

            if(l == -1)
              left = NULL;
            else
              left = new mytree(l);
            if(r == -1)
              right = NULL;
            else
              right = new mytree(r);

            p->left = left;
            p->right = right;

            if(p->left)
              t.push(p->left);
            if(p->right)
              t.push(p->right);
        }
    }

    return root;
}

int count_node(mytree* root)
{
    if(root == NULL)
    {
       return 0;
    }

    int l = count_node(root->left);
    int r = count_node(root->right);

    return l+r+1;
}

void levelorder_output(mytree* root)
{
    queue<mytree*> t;

    if(root == NULL)
      return;
    else
    {
        t.push(root);

        while(!t.empty())
        {
            mytree* p = t.front();
            t.pop();

            cout << p->val << " ";

            if(p->left)
              t.push(p->left);
            if(p->right)
              t.push(p->right);
              
        }
    } 
}

int main()
{
    mytree* root = NULL;

    root = input_tree(root);

    cout << "Level order Print :- " << endl;

    levelorder_output(root);

    cout << endl;

    int count = count_node(root);

    cout << "Total count of Nodes :- " << count << endl;
    
    return 0;
}