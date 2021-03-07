/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
   struct ListNode *fast=head;
   struct ListNode *slow=head;
   while(fast&&fast->next) 
   {
       fast=fast->next->next;
       slow=slow->next;
       if(fast==slow)
            break;
   }
   if(fast==NULL||fast->next==NULL)
   {
       return NULL;
   }
   struct ListNode * meet=fast;
   while(head!=meet)
   {
       head=head->next;
       meet=meet->next;
   }
   return head;
}