/*
    Soln:
    1- Brute force 
    -> every array of size k is iterated and its median value was calculated
    -> STL used: nth_element 
    -> nth_element: STL algorithm which rearranges the list in such a way such that
        the element at the nth position is the one which should be at that position
        if we sort the list
*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define vl vector<ll>
#define Map map<ll, ll>
#define vvl vector<vector<ll>>
#define pb push_back
#define PYes cout<<"YES\n"
#define PNo cout<<"NO\n"
#define fl(i, a, b) for(int i=a;i<b;i++)
#define endl "\n"
#define cov(x) (x).begin(),(x).end()

class Solution {
public:
    int n;
    double median(vector<int> a)
    {
        if (n % 2 == 0) {
  
            // Applying nth_element
            // on n/2th index
            nth_element(a.begin(),
                        a.begin() + n / 2,
                        a.end());

            // Applying nth_element
            // on (n-1)/2 th index
            nth_element(a.begin(),
                        a.begin() + (n - 1) / 2,
                        a.end());

            // Find the average of value at
            // index N/2 and (N-1)/2
            return (double)((long long)a[(n - 1) / 2]+ (long long)a[n / 2])/ 2.0;
        }

        // If size of the arr[] is odd
        else {

            // Applying nth_element
            // on n/2
            nth_element(a.begin(),
                        a.begin() + n / 2,
                        a.end());

            // Value at index (N/2)th
            // is the median
            return (double)a[n / 2];
        }
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        n = k;
        vector<double> ans;
        
        vector<int> temp;
        int i = 0, j = 0;
        while(j < nums.size())
        { 
            temp.push_back(nums[j]);
                // j++;
            if(temp.size() == k)
            {
                double curr = median(temp);
                // cout<<"curr: "<<curr<<endl;
                ans.push_back(curr);
                temp.erase(temp.begin());
            }
            j++;
        }
        
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    
    return 0;
}