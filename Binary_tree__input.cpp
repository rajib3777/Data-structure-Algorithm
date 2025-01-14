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
       root = NULL;

    else
    {
        root = new mytree(val);
        queue<mytree*> t;

        if(root)
        {
            t.push(root);
        }

        while(!t.empty())
        {
            mytree* P = t.front();
            t.pop();

            int l,r;
            cin >> l >> r;
            mytree *myleft,*myright;

            if(l == -1)
              myleft = NULL;
            else
              myleft = new mytree(l);
            if(r == -1)
              myright = NULL;

            else
              myright = new mytree(r);

            P->left = myleft;
            P->right = myright;

            if(P->left)
               t.push(P->left);
            if(P->right)
               t.push(P->right);
              
        }   

    }

    return root;
}

void inorder_output(mytree* root)
{
    if (root == NULL)
      return;

    inorder_output(root->left);
    cout << root->val << " ";
    inorder_output(root->right);

}

void preorder_output(mytree* root)
{
    if (root == NULL)
      return;

    cout << root->val << " ";
    inorder_output(root->left);
    inorder_output(root->right);
}

void postorder_output(mytree* root)
{
    if (root == NULL)
      return;

    inorder_output(root->left);
    inorder_output(root->right);
    cout << root->val << " ";
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

    cout << "Inorder Output" << endl;

    inorder_output(root);

    cout << endl;

    cout << "preorder Output" << endl;

    preorder_output(root);

    cout << endl;

    cout << "postorder Output" << endl;

    postorder_output(root);

    cout << endl;

    cout << "levelorder Output" << endl;

    levelorder_output(root);

    
    return 0;
}