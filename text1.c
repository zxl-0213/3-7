/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
    void reverselist(ListNode** head){
    ListNode* newnode=NULL;

    ListNode* cur=*head;
   
    while(cur)
    {
        cur=cur->next;
        (*head)->next=newnode;
        newnode=*head;
      
        *head=cur;
            
    }
    *head=newnode;
}
class Solution {
public:
    /**
     * 
     * @param head ListNode类 the head
     * @return bool布尔型
     */
     
    bool isPail(ListNode* head) {
        // write code here
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev=NULL;
        while(fast!=NULL&&fast->next!=NULL)
        {
            prev=slow;
            fast=fast->next->next;
            slow=slow->next;
        }
        prev->next=NULL;
        reverselist(&slow);
        while(head)
        {
            if(head->val!=slow->val)
            {
                return false;
            }
            else
            {
                head=head->next;
                slow=slow->next;
            }
        }
        return true;
    }
};