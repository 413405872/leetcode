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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL||k<=0)
        {
            return head;
        }
        ListNode* pHead=head;
        ListNode* pNode=head;
        ListNode* pLast=head;
        ListNode* pNodek=head;
        int n=0;
        while(pNode!=NULL)//出来以后pLast指向链表最后一个结点，而pNode=pLast->next是NULL
        {
            pLast=pNode;
            pNode=pNode->next;
            n++;
        }
        if(k>n)//这个如果k是大于链表长度的，那么就去掉整数倍部分
        {
            k=k%n;
        }
        if(k==n||k==0)//如果k=0或者n那就不用反转
        {
            return head;
        }
        int i=n-k;
        while(i>0)//此时pNodek已经到了该选择的那个点,且记录pNodek的前一个结点pNode。
        {
            pNode=pNodek;
            pNodek=pNodek->next;
            i--;
        }
        pNode->next=pLast->next;
        pLast->next=pHead;
        head=pNodek;
        return head;
        
        
    }
};