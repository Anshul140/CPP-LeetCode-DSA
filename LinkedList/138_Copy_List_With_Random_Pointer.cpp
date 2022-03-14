/*
<-- Definition for a Node.  -->
*/
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

//Brute Force 
/*
TC: O(n) 
SC: O(n)
*/
class Solution1 {
public:
    Node* copyRandomList(Node* head) {

        //maps Actual node to newly created node
        map<Node*, Node*> mp;
        
        Node *t = head;
        Node *nh = new Node(100000);
        while(t != NULL)
        {
            Node *curr = new Node(t->val);
            mp[t] = curr;
            t = t->next;
        }
        
        t = head;
        while(t != NULL)
        {
            Node *curr = mp[t];
            curr->next = mp[t->next];
            curr->random = mp[t->random];  
            t = t->next;
        }
        
        return mp[head];
    }
};

/*
TC: O(n) 
SC: O(1) apart from deep copy nodes
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        //1-> creating deep copy nodes
        Node *it, *front;
        it = front = head;
        while(it != NULL)
        {
            front = it->next;
            Node *copy = new Node(it->val);
            it->next = copy;
            copy->next = front;
            it = front;
        }
        
        //2-> handling random pointers of deep copy nodes
        it = head;
        while(it != NULL)
        {
            if(it->random != NULL)
            {
                it->next->random = it->random->next;
            }
            it = it->next->next;
        }
        
        //3-> detaching deep copy nodes and actual list
        it = front = head;
        Node *dmy = new Node(0);
        Node *temp = dmy; 
        while(it != NULL)
        {
            front = it->next->next;
            temp->next = it->next;
            it->next = front;
            temp = temp->next;
            it = it->next;
        }
        
        return dmy->next;
    }
};

int main()
{
    return 0;
}