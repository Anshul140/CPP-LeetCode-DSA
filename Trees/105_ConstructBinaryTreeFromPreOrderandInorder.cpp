#define mp map<int, int>
class Solution {
public:
    TreeNode* treeBuilder(vector<int>& pre, int preStart, int preEnd,
                          vector<int>& ino, int inStart, int inEnd, mp& inMap)
    {
        if(preStart > preEnd or inStart > inEnd) return NULL;
        
        TreeNode *root = new TreeNode(pre[preStart]);
        
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;
        
        root->left = treeBuilder(pre, preStart+1, preStart+numsLeft, ino, inStart, inRoot-1, inMap);
        root->right = treeBuilder(pre, preStart+numsLeft+1, preEnd, ino, inRoot+1, inEnd, inMap);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& ino) {
        map<int, int> inMap;
        
        for(int i = 0; i<ino.size(); i++) inMap[ino[i]] = i;
        
        TreeNode *root = treeBuilder(pre, 0, pre.size() - 1, ino, 0, ino.size()-1, inMap);
        
        return root;
    }
};