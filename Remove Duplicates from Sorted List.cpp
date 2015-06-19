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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head==NULL||head->next==NULL)//空链表或者一个结点的链表都直接返回
        {
            return head;
        }
        ListNode* pNode1=head;
        ListNode* pNode2=head->next;//此时我们已经知道至少有两个结点了
        while(pNode2!=NULL)
        {
            while(pNode2!=NULL&&pNode1->val==pNode2->val)//一定要判断pNode2.因为他要跑的
            {
                pNode1->next=pNode2->next;
                pNode2=pNode2->next;
            }
            if(pNode2!=NULL)
            {
                pNode1=pNode2;
                pNode2=pNode2->next;
            }
        }
        return head;
        
    }
};