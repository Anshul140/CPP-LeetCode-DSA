class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int x) {
        if(root == NULL)
            return NULL;
        if(root->val == x)
            return root;
        if(x < root->val)
            return searchBST(root->left, x);
        else
            return searchBST(root->right, x);
    }
};