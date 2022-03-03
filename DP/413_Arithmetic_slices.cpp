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
#define all(x) (x).begin(),(x).end()
#define endl "\n"


int numberOfArithmeticSlices(vector<int>& nums) {
   int n = nums.size();
   if(n < 3) return 0;
   long long int i = 2, j = 1, ans = 0;

   while(j < n)
   {
       int tj = j, ti = i;
       while(i < n and (nums[i] - nums[tj] == nums[tj] - nums[tj-1]))
          i++, tj++;
       long long int sz = tj - j + 2;
       ans += (sz*(sz+1)/2);
       ans -= (sz + sz - 1);
       j = i;
       i++;
   }

//    cout<<ans<<endl;
   return (int)ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    vector<int> nums = {1, 2};
    cout<<numberOfArithmeticSlices(nums)<<endl;
    return 0;
}