/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode * curA=headA;
    struct ListNode * curB=headB;
    int la=0,lb=0;
    while(curA)
    {
        la++;
        curA=curA->next;
    }
    curA=headA;
    while(curB)
    {
        lb++;
        curB=curB->next;
    }
    curB=headB;
    struct ListNode * len=headA;
    if(la<lb)
        len=headB;
    int gap=abs(la-lb);
    while(gap--)
    {
        len=len->next;
        if(la>lb)
            curA=len;
        else
            curB=len;
    }
   // struct ListNode *longlist=headA;
   // struct ListNode *shortlist=headB;
   /* if(la<lb)
    {
        longlist=headB;
        shortlist=headA;
    }
    int gap=abs(la-lb);*/
    /*while(gap--)
    {
        longlist=longlist->next;
    }*/
    while(curA)
    {
        if(curA==curB)
        {
            return curA;
        }
        else
        {
            curA=curA->next;
            curB=curB->next;
        }
    }
    return NULL;
}