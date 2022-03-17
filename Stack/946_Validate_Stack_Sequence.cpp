class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0;
        
        for(int el: pushed)
        {
            st.push(el);
            while(j < popped.size() and !st.empty() and st.top() == popped[j])
            {
                st.pop();
                j++;
            }
        }
        
        return j == popped.size();
    }
};