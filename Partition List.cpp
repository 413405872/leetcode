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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode* pNodeLess=new ListNode(-1);
        ListNode* pNodeGreat=new ListNode(-1);
        ListNode* pNode=head;
        ListNode* pLessHead=pNodeLess;
        ListNode* pGreatHead=pNodeGreat;
        while(pNode!=NULL)
        {
            if(pNode->val<x)//小于x的
            {
                pNodeLess->next=pNode;
                pNode=pNode->next;
                pNodeLess=pNodeLess->next;
                pNodeLess->next=NULL;
            }
            else//大于x的
            {
                pNodeGreat->next=pNode;
                pNode=pNode->next;
                pNodeGreat=pNodeGreat->next;
                pNodeGreat->next=NULL;
            }
        }
        if(pLessHead->next==NULL)//说明没有比x小的
        {
            head=pGreatHead->next;
            delete pLessHead;
            delete pGreatHead;
            return head;
        }
        if(pGreatHead->next==NULL)//说明没有比x大的
        {
            head=pLessHead->next;
            delete pLessHead;
            delete pGreatHead;
            return head;
        }
        //下面就是两组都有
        head=pLessHead->next;//去小头
        delete pLessHead;
        ListNode* head1=pGreatHead->next;//去大头
        delete pGreatHead;
        ListNode* pTemp=head;
        while(pTemp->next!=NULL)//找到小的链表的结尾
        {
            pTemp=pTemp->next;
        }
        pTemp->next=head1;//链接两个链表
        return head;
        
    }
};