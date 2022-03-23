//Method-1 Using DFS
class Solution {
public:
    vector<int> g[105];
    int vis[105];
    
    void reset()
    {
        for(int i = 0; i<=100; i++)
        {
            g[i].clear();
            vis[i] = 2;
        }
    }
    bool dfs(int v)
    {        
        for(int el: g[v])
        {
            if(vis[el] == 2)
            {
                vis[el] = vis[v]^1;
                if(!dfs(el)) return false;
            }
            else if(vis[el] == vis[v])
                return false;     
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        reset();
        int n = graph.size();
        
        for(int i = 0; i<n; i++)
        {
            for(int el:graph[i])
            {
                g[i].push_back(el);
                g[el].push_back(i);
            }
        }
        
        for(int i = 0; i<n; i++)
        {
            if(vis[i] == 2)
            {
                vis[i] = 0;
                if(!dfs(i)) return false;
            }
        }
        
        return true;
    }
};


//Method-2 Using BFS
class Solution2 {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // reset();
        int n = graph.size();
        vector<int> g[n+5];
        vector<int> vis(n+5, 2);
        for(int i = 0; i<n; i++)
        {
            for(int el:graph[i])
            {
                g[i].push_back(el);
                g[el].push_back(i);
            }
        }
        
        //BFS-method using extra array for coloring
        queue<int> q;
        for(int i = 0; i<n; i++)
        {
           if(vis[i] == 2)
           {
                q.push(i);
                vis[i] = 0;
                while(!q.empty())
                {
                    int x = q.front();
                    // int curr_col = vis[x];
                    q.pop();
                    for(int i: g[x])
                    {
                        if(vis[i] == 2)
                        {
                            vis[i] = vis[x]^1;
                            q.push(i);
                        }   
                        else if(vis[x] == vis[i])
                            return false;
                    }
                }    
            }
        }
        return true;
    }
};