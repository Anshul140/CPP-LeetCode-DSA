/*
Implemented Stack using two queues(q1, q2)
Approach:
push(x)
  -> add(x)-q2
  -> add all the values of q1 to q2(element by element)
  -> swap(q1, q2)
pop()
  -> x = q1.front()
  -> q1.pop() 
*/

class MyStack {
public:
    queue<int> q1, q2;
    MyStack() {
        
    }    
    void push(int x) {
        q2.push(x);
        
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        
        swap(q1, q2);
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


