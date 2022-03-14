class Solution {
public:
    TreeNode* treeBuilder(vector<int>& inod, int inStart, int inEnd, 
                          vector<int>& post, int postStart, int postEnd, map<int, int>& mp)
    {
        if(inStart > inEnd or postStart > postEnd) return NULL;
        
        TreeNode *root = new TreeNode(post[postEnd]);
        int inRoot = mp[root->val];
        int numsLeft = inRoot - inStart - 1;
        
        root->left = treeBuilder(inod, inStart, inRoot-1, post, postStart, postStart+numsLeft, mp);
        
        root->right = treeBuilder(inod, inRoot+1, inEnd, post, postStart+numsLeft+1, postEnd-1, mp);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inod, vector<int>& post) {
        map<int, int> inMap;
        
        for(int i = 0; i<inod.size(); i++) inMap[inod[i]] = i;
        
        TreeNode *root = treeBuilder(inod, 0, inod.size()-1, post, 0, post.size() - 1, inMap) ;
        
        return root;
    }
};