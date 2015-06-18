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
    ListNode* reverseList(ListNode* head)//反转一个链表
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
    ListNode* findLast(ListNode* head)//找出链表最后一个节点
    {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode* LastOne=head;
        while(LastOne->next!=NULL)
        {
            LastOne=LastOne->next;
        }
        return LastOne;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||head->next==NULL||k<=1)
        {
            return head;
        }
        int n=0;
        ListNode* pNode=head;
        while(pNode!=NULL)//统计链表的结点个数
        {
            pNode=pNode->next;
            n++;
        }
        pNode=head;
        if(k>n)
        {
            return head;
        }
        if(k==n)//需要旋转的节点比现在都多，那我只能旋转所有的了
        {
            head=reverseList(head);
            return head;
        }
        ListNode* newNode=new ListNode(-1);//引入一个辅助结点
        ListNode* pHead=newNode;
        //下面是k个节点在n范围内
        int Circle=n/k;
        //int left=n%k;
        for(int i=0;i<Circle;i++)
        {
            ListNode* pCurrent=pNode;
            int j=1;
            while(k>j)
            {
                pCurrent=pCurrent->next;
                j++;
            }//pCurrent出来以后指向的是第k个节点
            ListNode* pNext=pCurrent->next;
            pCurrent->next=NULL;
            pNode=reverseList(pNode);
            newNode->next=pNode;
            newNode=findLast(pNode);
            pNode=pNext;
        }
        newNode->next=pNode;//这个是处理剩余的东西。
        head=pHead->next;
        delete pHead;
        return head;
        
    }
};