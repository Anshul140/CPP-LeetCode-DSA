/*
Algorithm:
   - data-structures to be used:
     - mapStk: map<int, stack<int>>: store frequency wise stack of elements(for each frequency, sequence of elments)
     - freqMap: map<int, int>: frequency of each elements
     - int maxFreq: stores current maximum frequency of elements
   - push(val):
     -> update frequency in freqMap
     -> update maxFreq if applicable
     -> push val into stack of key freqMap[val] in mapStk
   - pop():
     -> return and remove top element of stack where key is maxFreq
     -> if stack becomes empty in mapStk, then reduce maxFreq--
     -> reduce count from freqMap  
*/

class FreqStack {
public:
    map<int, stack<int>> mpStk;
    map<int, int> freqMap;
    int maxFreq;
    FreqStack() {
        mpStk.clear();
        freqMap.clear();
        maxFreq = 0;
    }
    
    void push(int val) {
        freqMap[val]++;
        if(freqMap[val] > maxFreq)
            maxFreq = freqMap[val];
        mpStk[freqMap[val]].push(val);
    }
    
    int pop() {
        int ans = mpStk[maxFreq].top();
        mpStk[maxFreq].pop();
        
        if(mpStk[maxFreq].empty()) maxFreq--;
        
        freqMap[ans]--;
        if(freqMap[ans] == 0) freqMap.erase(ans);
        
        return ans;
    }
};