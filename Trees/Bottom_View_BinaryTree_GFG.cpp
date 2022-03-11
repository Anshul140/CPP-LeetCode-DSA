#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  struct node * left, * right;
};

vector <int> bottomView(Node *root) {
    //line- numbering of imaginary vertical lines (root: 0, root-Left: -1... so on, and root-right: 1,...so on)

    //map of <line-number, node-value>
    map<int, int> mp;

    //queue of <node->val, line-number>
    queue<pair<Node*, int>> q;
    
    vector<int> ans;
    if(root == NULL) return ans;
    
    q.push({root, 0});
    while(!q.empty())
    {
        int sz = q.size();
        for(int i = 0; i<sz; i++)
        {
            auto it = q.front();
            q.pop();
            
            Node *curr = it.first;
            mp[it.second] = curr->data;
            if(curr->left != NULL)
                q.push({curr->left, it.second - 1});
            if(curr->right != NULL)
                q.push({curr->right, it.second + 1});
        }
    }

    for(auto it: mp)
    {
        ans.push_back(it.second);
    }

    return ans;
}

int main()
{
    return 0;
}