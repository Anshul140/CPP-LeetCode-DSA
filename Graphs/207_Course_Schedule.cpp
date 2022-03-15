/*
Algorithm:
   ->Cycle detection in directed graphs
   ->if detected: return false
   ->else: return true
*/

class Solution {
public: 
   vector<int> g[100005];
    bool vis[100005];
    bool dvis[100005];
    
    void reset()
    {
        for(int i = 0; i<=100000; i++) 
        {
            g[i].clear();
            vis[i] = false;
            dvis[i] = false;
        }    
    }
    
    bool isCyclic(int v)
    {
        vis[v] = true;
        dvis[v] = true;
        for(int el: g[v])
        {
            if(!vis[el])
            {
                if(isCyclic(el))
                   return true;
            }
            else if(dvis[el])
                return true;
        }
        dvis[v] = false;
        return false;
    }
    
    bool canFinish(int noc, vector<vector<int>>& preq) {
        int edges = preq.size();
        reset();
        for(int i = 0; i<edges; i++)
        {
            int a = preq[i][0], b = preq[i][1];
            g[a].push_back(b);
        }
        
        // int ans = false;
        for(int i = 0; i<noc; i++)
        {
            if(!vis[i])
            {
                if(isCyclic(i)) return false;
            }
        }
        return true;
    }
};