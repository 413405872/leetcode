/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        if(head==NULL)
        {
            return head;
        }
        ListNode* pNode1=head;
        while(pNode1!=NULL&&pNode1->val==val)//首先是从头部开始
        {
            pNode1=pNode1->next;
        }
        head=pNode1;
        ListNode* pNode2=head;
        while(pNode2!=NULL)
        {
            ListNode* pTemp=pNode2->next;
            while(pTemp!=NULL&&pTemp->val==val)
            {
                pTemp=pTemp->next;
            }
            pNode2->next=pTemp;
            pNode2=pTemp;
        }
        return head;
        
    }
};