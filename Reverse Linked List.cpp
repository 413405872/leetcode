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
    ListNode* reverseList(ListNode* head) {
    if(head==NULL||head->next==NULL)    {
        
        return head;
    }
    
    ListNode* pPre=NULL;
    ListNode* pNode=head;
    ListNode* pNext=head->next;
    while(pNext!=NULL)
    {
       ListNode* pTemp=pNext->next;
       
       if(pPre==NULL)
        pNode->next=pPre;
        pNext->next=pNode;
        pPre=pNode;
        pNode=pNext;
        pNext=pTemp;
    }
    head=pNode;
    return head;
    }
};