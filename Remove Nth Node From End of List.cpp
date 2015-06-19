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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        
        if(head==NULL||n<0)//就是处理特殊情况
        {
            return head;
        }
        ListNode* p=head->next;
        int m=1;
        while(p!=NULL)
        {
            p=p->next;
            m++;
        }
        if(m<n)//处理输入进来的数超过了链表的长度
        {
            return head;
        }
        ListNode* pNode1=head;
        ListNode* pNode2=head;
        int i=1;
        if(i==n&&pNode2->next!=NULL)//表明就是尾结点了;且不止一个结点。
        {
            while(pNode2->next!=NULL)
            {
                pNode1=pNode2;
                pNode2=pNode2->next;
            }
            pNode1->next=pNode2->next;
            return head;
        }
        while(i<=n&&pNode2!=NULL)
        {
            pNode2=pNode2->next;
            i++;
        }
        if(pNode2==NULL)//这个是处理删除头结点
        {
            head=head->next;
            return head;
        }
        while(pNode2!=NULL)
        {
            pNode1=pNode1->next;
            pNode2=pNode2->next;
        }
        pNode1->val=pNode1->next->val;
        pNode1->next=pNode1->next->next;
        return head;
        
    }
};