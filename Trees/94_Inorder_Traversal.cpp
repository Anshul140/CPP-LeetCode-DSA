// Iterative Inorder Traversal

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        
        while(root != NULL or !st.empty())
        {
            while(root != NULL)
            {
                st.push(root);
                root = root -> left;
            }
            
            root = st.top();
            st.pop();
            ans.push_back(root->val);
            
            root = root->right;
        }
        
        return ans;
    }
};