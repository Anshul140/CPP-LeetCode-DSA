/*
find k closest number to x in arr
   -> Priority queue stores absolute difference of each element in arr and actual element
   -> since we want closest numbers, difference must be minimum 
      -> hence using max heap
   -> based on difference priority queue is sorted
*/

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    priority_queue<pair<int, int>> pq;
    
    for(int el: arr)
    {
        pq.push({abs(el-x), el});
        
        if(pq.size() > k)
            pq.pop();
    }
    vector<int> ans;
    while(!pq.empty())
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
}