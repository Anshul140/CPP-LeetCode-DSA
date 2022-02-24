/*
Algorithm: 
push(x)
   -> take size of q1 before pushing x
   -> q1.push(x)
   -> while(sz > 0): 
      - pop elements from q1
      - and again push them to q1
      - sz--
*/

class MyStack {
public:
    queue<int> q1;
    MyStack() {
        
    }    
    void push(int x) {
        int sz = q1.size();
        q1.push(x);

        while(sz != 0)
        {
            int y = q1.front();
            q1.pop();
            q1.push(y);
            sz--;
        }
    }
    
    int pop() {
        int x = q1.front();
        q1.pop();
        return x;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.size() == 0;
    }
};
