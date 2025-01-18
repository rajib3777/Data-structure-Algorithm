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

void level_wise_print(tree* root,int X)
{
   if(root == NULL)
   {
      cout << "Invalid" << endl;
      return ;
   }

   queue<tree*> q;
   q.push(root);

   int Y = 0;

   for(int Y = 0 ;!q.empty() ;Y++)
   {
      int Z = q.size();

      if(Y == X)
      {
         for(int i = 0; i < Z ; i++)
         {
            tree* p = q.front();
            q.pop();

            if(i > 0)
              cout << " ";
              cout << p->val;
         }
         return;
      }

      for(int i = 0; i < Z; i++)
      {
         tree* p = q.front();
         q.pop();

         if(p->left)
           q.push(p->left);
         if(p->right)
           q.push(p->right);
      }
   }

   cout << "Invalid" << endl;
}
int main()
{
    tree* root = NULL;

    root = input_tree(root);

    int X;
    cin >> X;

    level_wise_print(root,X);


    return 0;
}