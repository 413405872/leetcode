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
    bool hasCycle(ListNode *head) {
        bool DoHaveCircle=false;
        if(head==NULL||head->next==NULL)
        {
            return false;//空链表没环
        }
        if(head->next==head)
        {
            return true;
        }
        ListNode* pNode1=head;
        ListNode* pNode2=head->next->next;
        while(pNode1!=NULL&&pNode2!=NULL)
        {
            if(pNode1==pNode2)
            {
                return true;
            }
            pNode1=pNode1->next;
            if(pNode2!=NULL)
            {
                pNode2=pNode2->next;
            }
            if(pNode2!=NULL)
            {
                pNode2=pNode2->next;
            }
        }
        return false;
        
        
    }
};