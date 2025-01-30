//function
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> V;

       post_order_rec(root,V);

        return V;
    }

    void post_order_rec(TreeNode* root, vector<int>& V)
    {
        if(root == NULL)
           return;

        post_order_rec(root->left,V);
        post_order_rec(root->right,V);
        V.push_back(root->val);
    }
};