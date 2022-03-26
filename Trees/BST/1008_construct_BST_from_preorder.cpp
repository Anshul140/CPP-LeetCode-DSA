// Approach-1 : inorder traversal of any BST gives a sorted array
// hence we can obtain inorder traversal from preorder array
// we know that, preorder and inorder traversal can give unique tree 
// here its a Binary Search Tree  
// TC: O(n), SC: O(n)
class Solution {
public:
    int n;
    TreeNode* buildBSTree(vector<int>& pre, int ps, int pe, vector<int>& ino, int is, int ie, 
                        map<int, int>& mp)
    {
        if(ps > pe or is > ie) return NULL;
        
        TreeNode *root = new TreeNode(pre[ps]);
        
        int inRoot = mp[root->val];
        int left = inRoot - is;
        
        root->left = buildBSTree(pre, ps+1, ps+left, ino, is, inRoot-1, mp);
        root->right = buildBSTree(pre, ps+left+1, pe, ino, inRoot+1, ie, mp);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        n = pre.size();
        
        //inorder is sorted array in BST
        vector<int> ino(n);
        for(int i = 0; i<n; i++)
            ino[i] = pre[i];
        sort(ino.begin(), ino.end());
        map<int, int> inMap; 
        for(int i = 0; i<n; i++) inMap[ino[i]] = i;
        
        TreeNode *root = buildBSTree(pre, 0, n-1, ino, 0, n-1, inMap);
        
        return root;
    }
};

//Approach-2 
/*
   -> set i = 0, upperBound(ub) = INT_MAX
   -> Recursively check  
        - if(i > n or pre[i] > ub): return NULL
        - set root as pre[i++]
        - call for root->left with upper bound as root->val
        - call for root->right with upper bound as ub
   -> TC: O(n), SC: O(1)     
*/
class Solution {
public:
    int n;
    TreeNode* buildBSTree(vector<int>& pre, int& i, int ub)
    {
        if(i == n or pre[i] > ub) return NULL;
        
        TreeNode *root = new TreeNode(pre[i++]);
        root->left = buildBSTree(pre, i, root->val);
        root->right = buildBSTree(pre, i, ub);

        return root;

    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        n = pre.size();
        int i = 0;
        return buildBSTree(pre, i, INT_MAX);
    }
};
