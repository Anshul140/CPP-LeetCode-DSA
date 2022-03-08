/*
Soln:
  -> using multiset + sliding window
  -> keeping an iterator to the mid position
  -> after new element is inserted 
     - check if new element is smaller than mid, if yes then mid--
  -> check if element to be removed from window is less than or equal to mid
     - if yes then mid++
  -> erase from multiset
  -> inside median fn(iterator, k):
     - if k odd: return mid
     - else firstNumber = *mid, secondNumber = *(--mid)
           - return (firstN + secondN)/2.0
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double median(multiset<int>::iterator mid, int k)
    {
        if(k & 1) return *(mid);
        
        double first = *(mid--);
        double second = *(mid);
        
        return (first+second)/2.0;
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        
        multiset<int> ms;
        for(int i = 0; i<k; i++) ms.insert(nums[i]);
        
        auto mid = ms.begin();
        for(int i = 0; i<(k/2); i++) mid++;
        ans.push_back(median(mid, k));
        
        int i = 0, j = k;
        while(j < nums.size())
        {
            ms.insert(nums[j]);
            if(nums[j] < *(mid)) mid--;
            if(nums[i] <= *(mid)) mid++;
            
            ms.erase(ms.find(nums[i++]));
            ans.push_back(median(mid, k));
            j++;
        }
        return ans;
    }
};

int main(){
    return 0;
}
