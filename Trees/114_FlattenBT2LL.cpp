/*
Method-1(Recursive)
   Right, Left, Do some operation
TC: O(n)
SC: O(n)   
*/
class Solution {
public:
    TreeNode *prev = NULL;
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        
        flatten(root->right);
        flatten(root->left);
        
        root->right = prev;
        root->left = NULL;
        
        prev = root;
    }
};


/*
Method-2(Iterative)
TC: O(n)
SC: O(1)
*/

class Solution2 {
public:
    void flatten(TreeNode* root) {
        TreeNode *curr = root;
        
        while(curr != NULL) {
            if(curr->left != NULL) {
                TreeNode *prev = curr->left;
                while(prev->right) prev = prev->right;
                
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};