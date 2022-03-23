/*
Algorithm(BFS):
   -> insert elements in queue in right to left order
   -> keep prev pointer, curr pointer
   -> on each level traversal:
      - if(i == 0): curr->next = NULL, prev = curr
      - if(i > 0): curr->next = prev, prev = curr
      - set prev as curr for next nodes 
      - if(curr->right exists): push it on queue
      - if(curr->left exists): push it on queue
*/


class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int sz = q.size();
            Node *prev;
            for(int i=0; i<sz; i++)
            {
                Node *curr = q.front();
                q.pop();
                if(i == 0)
                {
                    curr->next = NULL;
                    prev = curr;
                }    
                else
                {
                    curr->next = prev;
                    prev = curr;
                }
                if(curr->right != NULL)
                    q.push(curr->right);
                if(curr->left != NULL)
                    q.push(curr->left);
            }
        }
        
        return root;
    }
};

//method-2 DFS- Recursive
class Solution2 {
public:
    void connect(Node* l, Node* r)
    {
        if(l == NULL or r == NULL) return;
        
        l->next = r;
        
        connect(l->left, l->right);
        connect(r->left, r->right);
        connect(l->right, r->left);
    }
    Node* connect(Node* root) {
        if(root == NULL) return root;
        
        connect(root->left, root->right);
        return root;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/