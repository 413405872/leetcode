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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode* pNode=head;
        ListNode* pNext=pNode->next;
        head=pNext;
        pNext=pNext->next;
        head->next=pNode;
        while(pNext!=NULL)
        {
            //pNode->next=pNext;
            ListNode* pTemp=pNext->next;
            if(pTemp!=NULL)
            {
                pNode->next=pTemp;
                ListNode* p=pTemp->next;
                pTemp->next=pNext;
                pNode=pNext;
                pNext=p;
            }
            
            else{
                
                break;
            }
        }
        pNode->next=pNext;
        return head;
        
    }
};