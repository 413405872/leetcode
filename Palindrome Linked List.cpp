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
    ListNode* reverse(ListNode* head)
    {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* pPre=NULL;
        ListNode* pCur=head;
        ListNode* pNext=head->next;
        pCur->next=pPre;
        while(pNext!=NULL)
        {
            pPre=pCur;
            pCur=pNext;
            pNext=pNext->next;
            pCur->next=pPre;
        }
        return pCur;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return true;
        ListNode* pEnd=head;//第二个链表的尾结点
        ListNode* pBegin=head;//第一个链表的头结点
        ListNode* pMidPre=head;//第一个链表的尾结点
        ListNode* pMid=head;//第二个链表的头结点
        int count=1;
        while(pEnd->next!=NULL)//先统计结点个数
        {
            count++;
            pEnd=pEnd->next;
        }
        int half=(count-1)/2;
        while(half>=0)//找到一半
        {
            pMidPre=pMid;
            pMid=pMid->next;
            half--;
        }
        pMidPre->next=NULL;
        pMid=reverse(pMid);
        while(pBegin!=NULL&&pMid!=NULL)
        {
            if(pBegin->val!=pMid->val)
                return false;
            pBegin=pBegin->next;
            pMid=pMid->next;
        }
        return true;
        
    }
};