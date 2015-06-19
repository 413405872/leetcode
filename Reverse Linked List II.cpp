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
    ListNode* reverseList(ListNode* head) {//反正链表
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
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL||head->next==NULL||m==n)
        {
            return head;
        }
        int i=1;
        ListNode* pNode=head;
        ListNode* pNode_mPre=head;
        ListNode* pNode_m=head;
        ListNode* pNode_n=head;
        ListNode* pNode_nPos=head;
        while(m>i)
        {
            pNode_mPre=pNode_m;//指向了m的前一个结点。
            pNode_m=pNode_m->next;//第m个结点
            i++;
        }
        i=1;
        while(n>i)
        {
            pNode_n=pNode_n->next;//第n个结点
            i++;
        }
        if(m!=1)//这个顺序可不能颠倒。颠倒了，链表就断了
        {
            pNode_mPre->next=NULL;
        }
        pNode_nPos=pNode_n->next;//指向n的下一个结点。
        pNode_n->next=NULL;
        ListNode* newNode=reverseList(pNode_m);
        if(m!=1)
        {
            pNode_mPre->next=newNode;//前面的衔接
        }
        else
        {
            head=newNode;
        }
        while(newNode->next!=NULL)
        {
            newNode=newNode->next;
        }
        newNode->next=pNode_nPos;//后面的衔接
        return head;
        
        
        
    }
};