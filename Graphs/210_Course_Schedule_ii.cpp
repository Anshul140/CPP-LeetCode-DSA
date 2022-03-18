/*
Topological Sort: Linear indexing of vertices such that if there is an edge u -> v, then
                  u appears before v in the ordering
-> Only valid for Directed Acyclic Graphs(DAGs)                  
-> There can be multiple topo sort ordering for a graph      

->Algorithm:
    - simple dfs on directed graph
    - while returning from a node in dfs, put that node in stack
    - in main(): -empty the elements of stack in vector
                 -bottom to top of stack will give topological sorted order(reverse vector obtained above )            
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
    
    stack<int> st;
    void topoSort(int v)
    {
        vis[v] = true;
        for(int el: g[v])
        {
            if(!vis[el])
                topoSort(el);
        }
        
        st.push(v);
    }
    
    vector<int> findOrder(int noc, vector<vector<int>>& preq) {
        int edges = preq.size();
        reset();
        for(int i = 0; i<edges; i++)
        {
            int a = preq[i][0], b = preq[i][1];
            g[a].push_back(b);
        }
        
        // int ans = false;
        vector<int> ans;
        for(int i = 0; i<noc; i++)
        {
            if(!vis[i])
            {
                if(isCyclic(i)) return ans;
            }
        }
        
        for(int i = 0; i<noc; i++) vis[i] = false;
        
        for(int i = 0; i<noc; i++)
        {
            if(!vis[i]) topoSort(i);
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};