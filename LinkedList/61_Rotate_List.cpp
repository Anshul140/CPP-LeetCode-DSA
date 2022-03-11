/*
Algorithm:
   -> calculate length of LL(n)
   -> calculate rotation value(rotn) between 1 and n-1 (if rotn % n == 0 return head)
   -> connect end of LL to head 
   -> iterate from start till (n - rotn - 1) position
   -> reinitialize head
   -> change last node

T.C: O(n) 
S.C: O(1)   
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL or head->next == NULL or k == 0) return head;
        
        int len = 1;
        ListNode *t = head, *t1 = head;
        while(t->next != NULL)
        {
            len++;
            t = t->next;
        }
        
        int rotn = k % len;
        if(rotn == 0) return head;
        t->next = head;
        
        t = head;
        for(int i = 0; i<len-rotn-1; i++)
            t = t->next;
        head = t->next;
        t->next = NULL;
        
        return head;
    }
};