#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
     -3 -2 -1 0 1 2 3  -> x-axis(vertical)
              1
              2
              3
              4
              .
              .
              y-axis(level)    

*/

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //map stores: x-coordinate(vertical), y-coordinate(level), node->val(s) in each [x][y] 
        map<int, map<int, multiset<int>>> mp;
        
        //queue stores: Node, (x, y) coordinates of the node
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        
        q.push({root, {0, 0}});
        while(!q.empty())
        {
            int sz = q.size();
            for(int i = 0; i<sz; i++)
            {
                auto it = q.front();
                q.pop();
                
                TreeNode *curr = it.first;
                int x = it.second.first, y = it.second.second;
                
                mp[x][y].insert(curr->val);
                if(curr->left != NULL)
                    q.push({curr->left, {x-1, y+1}});
                if(curr->right != NULL)
                    q.push({curr->right, {x+1, y+1}});
            }
        }
        
        for(auto it: mp)
        {
            vector<int> cv;
            for(auto it2: it.second)
            {
                cv.insert(cv.end(), it2.second.begin(), it2.second.end());
            }
            ans.push_back(cv);
        }
        
        return ans;
    }
};

int main()
{
    return 0;
}