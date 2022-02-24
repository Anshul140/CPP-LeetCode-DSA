/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/* Merge Sort Approach  */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        if(l1->val > l2->val)
            swap(l1, l2);
        ListNode *res = l1;
        while(l1 and l2)
        {
            ListNode *tmp = NULL;
            while(l1 and l1->val <= l2->val)
            {
                tmp = l1;
                l1 = l1->next;
            }
            tmp->next = l2;
            swap(l1, l2);
        }
        return res;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL or head->next == NULL)
            return head;
        ListNode *slow, *fast;
        slow = fast = head;
        
        // finding mid point of linkedList
        while(fast->next and fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // detaching first and second half
        fast = slow->next;
        slow->next = NULL;
        
        // returning the merged list after all detachments
        return mergeTwoLists(sortList(head), sortList(fast));
    }
};