// Inorder Traversal

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        
        st.push(root);
        while(!st.empty())
        {
            TreeNode *curr = st.top();
            st.pop();
            if(curr != NULL)
            {
                ans.push_back(curr->val);
                st.push(curr->right);
                st.push(curr->left);
            }
            
        }
        
        return ans;
    }
};