/*
Algorithm:
   -> bfs for shortest paths with some modifications
   -> queue stores [node, [dist, mask]]
   -> binary num: representing the visited and unvisted nodes
   -> set-DS keeps track of node and mask which are already visited
   -> if mask is of form 1111....(till n-1) then we return (current distance+1 )
*/
class Solution {
public:
    vector<int> g[20];
    int n;
    
    int bfs()
    {
        queue<pair<int, pair<int, int>>> q;
        set<pair<int, int>> vis;
        int allVis = (1<<n) - 1;
        
        for(int i = 0; i<n; i++)
        {
            int mask = 1<<i;
            q.push({i, {0, mask}});
            vis.insert({i, mask});
        }
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int num = it.first, dist = it.second.first, mask = it.second.second;
            
            for(auto ch: g[num])
            {
                int newMask = mask | (1<<ch);
                
                if(newMask == allVis)
                    return dist + 1;
                else if(vis.count({ch, newMask}))
                    continue;
                else{
                    q.push({ch, {dist+1, newMask}});
                    vis.insert({ch, newMask});
                }
            }
        }
        
        return 0;
    }
    
    int shortestPathLength(vector<vector<int>>& graph) {
        for(int i = 0; i< 20; i++)
        {
            g[i].clear();
        }
        
        n = graph.size();
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<graph[i].size(); j++)
            {
                g[i].push_back(graph[i][j]);
                g[graph[i][j]].push_back(i);
            }
        }
        
        return bfs();
    }
};