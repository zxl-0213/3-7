/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 * };
 */
 
class Solution {
public:
    /**
     *
     * @param head ListNode类
     * @param x int整型
     * @return ListNode类
     */
    ListNode* partition(ListNode* head, int x) {
        // write code here
        ListNode* smallhead,*smalltail;
        ListNode* greathead,*greattail;
        ListNode* cur=head;
       smallhead=smalltail=(ListNode*)malloc(sizeof(ListNode*));
       greathead=greattail=(ListNode*)malloc(sizeof(ListNode*));
       greathead->next=smallhead->next=NULL;
        while(cur)
        {
            if(cur->val>=x)
            {
              
                greattail->next=cur;
                greattail=greattail->next;
            }
            else
            {
                smalltail->next=cur;
                smalltail=smalltail->next;
            }
            cur=cur->next;
        }
         
        smalltail->next=greathead->next;
        greattail->next=NULL;
        ListNode* list=smallhead->next;
        free(greathead);
        free(smallhead);
        return list;
    }
};