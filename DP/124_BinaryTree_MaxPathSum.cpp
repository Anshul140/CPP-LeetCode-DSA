class Solution {
public:
    int solve(TreeNode* A, int& ans) { 
        if(A->left == NULL and A->right == NULL)
        {
            ans = max(ans, A->val);
            return A->val;
        }   

        // ls-> left subtree sum, rs -> right subtree sum
        int ls = 0, rs = 0;   
        if(A->left != NULL)   
            ls = solve(A->left, ans);
        if(A->right != NULL)    
            rs = solve(A->right, ans);

        int curr1 = max(ls, rs) + A->val;
        int curr2 = ls + rs + A->val;
        ans = max({ans, curr1, curr2, A->val});

        return max(curr1, A->val);    
    }
    int maxPathSum(TreeNode* A) {
        int ans = A->val;
        int x = solve(A, ans);

        return ans;
    }
};