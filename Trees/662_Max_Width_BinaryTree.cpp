/*
Note:
   -> indexing of nodes are done
   -> 1 + (difference of rightmost and leftmost index)  can give width of a level
   ->            (i)   
                 / \
           (2*i+1) (2*i+2)
   -> for every level modified i = (actual i) - min(all indexes of current level)        
*/       

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        
        long long int ans = 0;
        queue<pair<TreeNode*, long long int>> q;
        
        q.push({root, 0});
        
        while(!q.empty()){
            int sz = q.size();
            long long int mn = q.front().second;
            long long int first, last;
            
            for(int i = 0; i<sz; i++)
            {
                long long c_id = q.front().second - mn;
                TreeNode* curr = q.front().first;
                q.pop();
                if(i == 0) first = c_id;
                if(i == sz - 1) last = c_id;
                if(curr->left)
                    q.push({curr->left, 2*c_id + 1});
                if(curr->right)
                    q.push({curr->right, 2*c_id + 2});
            }
            
            ans = max(ans, last - first + 1);
        }
        
        return (int)ans;
    }
};