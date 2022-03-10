/*
Input numbers are in reverse order i.e. l1 = [2,4,3] means actual number is 342

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode();
        ListNode *head = dummy;
        
        int carry = 0;
        while(l1 != NULL and l2 != NULL){
            int sum = l1->val + l2->val;
            sum += carry;
            carry = sum/10;
            ListNode *t = new ListNode(sum % 10);
            head->next = t;
            head = head->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL)
        {
            int sum = l1->val;
            sum += carry;
            carry = sum/10;
            ListNode *t= new ListNode(sum % 10);
            head->next = t;
            head = head->next;
            l1 = l1->next;
        }
        while(l2 != NULL)
        {
            int sum = l2->val;
            sum += carry;
            carry = sum/10;
            ListNode *t= new ListNode(sum % 10);
            head->next = t;
            head = head->next;
            l2 = l2->next;
        }
        
        if(carry > 0)
        {
            ListNode *t = new ListNode(carry);
            head->next = t;
            // head = head->next;
        }
        return dummy->next;
    }
};