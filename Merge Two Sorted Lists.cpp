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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
        {
            return l2;
        }
        if(l2==NULL)
        {
            return l1;
        }
        ListNode* lNode1=l1;
        ListNode* lNode2=l2;
        ListNode* newhead;
        if(lNode1!=NULL&&lNode2!=NULL)
        {
            if(lNode1->val>lNode2->val)//l2小，所以头结点
            {
                newhead=lNode2;
                lNode2->next=mergeTwoLists(lNode1,lNode2->next);
            }
            else//l1小，所以头结点
            {
                newhead=lNode1;
                lNode1->next=mergeTwoLists(lNode1->next,lNode2);
            }
        }
        return newhead;
        
    }
};