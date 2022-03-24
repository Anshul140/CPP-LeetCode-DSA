/*
Algorithm:
   -> make a buildTree(vi& nums, int left, int right) with return type as TreeNode*
   -> inside main():
      - call buildTree(nums, 0, n-1);
   -> inside buildTree:
      - if left > right: return NULL
      - int mid = (left + right) >> 1
      - TreeNode *curr = new TreeNode(nums[mid])
      - curr->left = buildTree(nums, left, mid-1)
      - curr->right = buildTree(nums, mid+1, right)   
*/

class Solution {
public:
    TreeNode* buildTree(vector<int>& nums, int left, int right)
    {
        if(left > right) return NULL;
        
        int mid = (left + right) >> 1;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = buildTree(nums, left, mid-1);
        node->right = buildTree(nums, mid+1, right);
        
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        
        return buildTree(nums, 0, n-1);
    }
};