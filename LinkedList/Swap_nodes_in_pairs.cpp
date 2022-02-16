// Recursive
void swap(ListNode *t)
{
    if (t == NULL)
        return;

    ListNode *first = t->next, *second = NULL;
    if (first != NULL)
        second = first->next;

    if (second != NULL)
    {
        ListNode *secondNxt = second->next;
        second->next = first;
        t->next = second;
        first->next = secondNxt;
        swap(first);
    }
}
ListNode *swapPairs(ListNode *head)
{
    ListNode *temp = head;

    if (head == NULL or head->next == NULL)
        return head;

    ListNode *dmy = new ListNode();
    dmy->next = head;

    swap(dmy);
    return dmy->next;
}

//Iterative
ListNode *swapPairs(ListNode *head)
{
    ListNode *dmy = new ListNode();
    dmy->next = head;
    ListNode *t = dmy;

    while(t != NULL){
        ListNode *first = t->next;
        ListNode *second = NULL;
        if(first != NULL)
           second = first->next;

        if(second != NULL){
            ListNode *secondNxt = second->next;
            second->next = first;
            t->next = second;
            first->next = secondNxt;
            t = first;
        } 
        else
           break;  
    }

    return dmy->next;
}