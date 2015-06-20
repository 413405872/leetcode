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
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode* pPre=NULL;
        ListNode* pNode=head;
        ListNode* pNext=head->next;
        while(pNext!=NULL)
        {
            while(pNext!=NULL&&pNode->val<=pNext->val)
            {
                pNode=pNode->next;
                pNext=pNext->next;
            }
            if(pNext!=NULL)
            {
                ListNode* pTemp=new ListNode(0);
                pTemp->val=pNext->val;
                pNode->next=pNext->next;//这个结点就被去掉了
                delete pNext;
                ListNode* CurrentNode=head;
                ListNode* pp=head;
                while(CurrentNode->val<=pTemp->val)
                {
                    pp=CurrentNode;
                    CurrentNode=CurrentNode->next;
                }
                if(pp==CurrentNode)//说明是头结点
                {
                    pTemp->next=CurrentNode;
                    head=pTemp;
                }
                else
                {
                    pTemp->next=CurrentNode;
                    pp->next=pTemp;
                }
                pNext=pNode->next;
            }
        }
        
        return head;
        
    }
};