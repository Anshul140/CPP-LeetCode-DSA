/*
Algorithm:
   -> convert costA into cost[] by adding 1 to each element of costA
   -> make a val[] containing values from 0 to 11
   -> convert this into 0-1 knapsack problem
   -> find a max value(ks -> knapsack value) that can be obtained
   -> use ks to find the desired array(i.e. elements which were included in knapsack)
   -> at last check if any unused arrows are remaining then add it in array
*/


class Solution {
public:
    vector<int> ans;
    int knapSack(int W, int wt[], int val[], int n)
    {
        int i, w;
        int K[n + 1][W + 1];

        // Build table K[][] in bottom up manner
        for (i = 0; i <= n; i++) {
            for (w = 0; w <= W; w++) {
                if (i == 0 || w == 0)
                    K[i][w] = 0;
                else if (wt[i - 1] <= w)
                    K[i][w] = max(val[i - 1] +
                        K[i - 1][w - wt[i - 1]], K[i - 1][w]);
                else
                    K[i][w] = K[i - 1][w];
            }
        }
 
        
        // stores the result of Knapsack
        int res1 = K[n][W];
        
        int res = K[n][W];
        // cout<< res << endl;

        w = W;
        for (i = n; i > 0 && res > 0; i--) {

            // either the result comes from the top
            // (K[i-1][w]) or from (val[i-1] + K[i-1]
            // [w-wt[i-1]]) as in Knapsack table. If
            // it comes from the latter one/ it means
            // the item is included.
            if (res == K[i - 1][w]) {
                ans.push_back(0);
                continue;
            }
                   
            else {

                // This item is included.
                // cout<<" "<<wt[i - 1] ;
                
                ans.push_back(wt[i-1]);
                

                // Since this weight is included its
                // value is deducted
                res = res - val[i - 1];
                w = w - wt[i - 1];
            }
        }
        return res1; // returning the maximum value of knapsack
    }
    vector<int> maximumBobPoints(int num, vector<int>& costA) {
        int n = costA.size();
        ans.clear();
        int cost[12], val[12];
        
        int i = 0;
        for(int el: costA)
            cost[i++] = el+1;
        for(int i = 0; i<12; i++)
        {
            val[i] = i;
        }
        
        int ks= knapSack(num, cost, val, 12);
        
        int used = 0;
        for(int el: ans) used += el;
        
        if(used < num)
            ans.push_back(num - used);
        
        while(ans.size() < 12)
        {
            ans.push_back(0);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};