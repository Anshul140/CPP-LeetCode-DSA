vector<string> summaryRanges(vector<int>& nums) {
    int n = nums.size();
    vector<string> ans;
    
    if(n == 0) return ans;
    
    int l = nums[0];
    for(int i = 1; i<n; i++)
    {
        long long x = (long long)nums[i] - (long long)nums[i-1];
        if(x != 1)
        {
            int c = nums[i-1];
            if(l == c)
            {
                string st = to_string(l);
                ans.push_back(st);
            } else {
                string st1 = to_string(l);
                string st2 = to_string(c);
                string s3 = "";
                s3 += st1;
                s3.push_back('-');
                s3.push_back('>');
                s3 += st2;
                
                ans.push_back(s3);
            }
            l = nums[i];
        }
    }
    if(l == nums[n-1])
    {
        string st = to_string(l);
        ans.push_back(st);
    } else{
        string st1 = to_string(l);
        string st2 = to_string(nums[n-1]);
        string s3 = "";
        s3 += st1;
        s3.push_back('-');
        s3.push_back('>');
        s3 += st2;

        ans.push_back(s3);
    }
    return ans;
}