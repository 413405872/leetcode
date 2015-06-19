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
    ListNode* reverseList(ListNode* head)//这个是反转链表
    {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode* pPre=NULL;
        ListNode* pCur=head;
        while(pCur!=NULL)
        {
            ListNode* pNex=pCur->next;
            pCur->next=pPre;
            pPre=pCur;
            pCur=pNex;
        }
        return pPre;
    }
public:
    ListNode* mergeList(ListNode* headA,ListNode* headB)//合并两个链表
    {
        ListNode* pNodeA=headA;
        ListNode* pNodeB=headB;
        while(pNodeA!=NULL)
        {
            ListNode* pNodeANext=pNodeA->next;
            pNodeA->next=pNodeB;
            ListNode* pNodeBNext=pNodeB->next;
            if(pNodeANext!=NULL)
            {
                pNodeB->next=pNodeANext;
            }
            pNodeB=pNodeBNext;
            pNodeA=pNodeBNext;
        }
        return headA;
    }
public:
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL)
        {
            return;
        }
        ListNode* pNode=head;
        ListNode* pMiddle=head;
        ListNode* pMiddlePre=head;
        ListNode* pMiddleHead=head;
        int n=0;//记录结点个数
        while(pNode!=NULL)
        {
            pNode=pNode->next;
            n++;
        }
        pNode=head;
        int half=n/2;
        while(half>0)
        {
            pMiddlePre=pMiddle;
            pMiddle=pMiddle->next;
            half--;
        }
        pMiddlePre->next=NULL;
        ListNode* pPre=NULL;
        ListNode* pCur=pMiddle;
        while(pCur!=NULL)
        {
            ListNode* pNex=pCur->next;
            pCur->next=pPre;
            pPre=pCur;
            pCur=pNex;
        }
        pMiddleHead=pPre;
        
        ListNode* pNodeA=head;
        ListNode* pNodeB=pMiddleHead;
        while(pNodeA!=NULL)
        {
            ListNode* pNodeANext=pNodeA->next;
            pNodeA->next=pNodeB;
            ListNode* pNodeBNext=pNodeB->next;
            if(pNodeANext!=NULL)
            {
                pNodeB->next=pNodeANext;
            }
            pNodeB=pNodeBNext;
            pNodeA=pNodeANext;
        }
        
    }
};