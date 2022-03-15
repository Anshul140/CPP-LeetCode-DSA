class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> st;
        set<int> idx;
        
        string ans = "";
        for(int i = 0; i<s.length(); i++)
        {
            if(s[i] == '(')
                st.push({s[i], i});
            else if(s[i] == ')'){
                if(!st.empty() and st.top().first == '(')
                    st.pop();
                else
                    idx.insert(i);
            }
        }
        
        while(!st.empty())
        {
            int i = st.top().second;
            idx.insert(i);
            st.pop();
        }
        
        for(int i = 0; i<s.length(); i++)
        {
            if(idx.find(i) == idx.end())
                ans.push_back(s[i]);
        }
         return ans;
    }
};