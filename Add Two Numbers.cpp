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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=NULL;
        if(l1==NULL&&l2==NULL)//如果是空的直接返回NULL
        {
            return head;
        }
        if(l1==NULL)//如果l1空，l2不空，返回l2
        {
            return l2;
        }
        if(l2==NULL)//如果l2空。l1不空,返回l1
        {
            return l1;
        }
        ListNode* newNode=new ListNode(l1->val+l2->val);//都不空
        head=newNode;
        l1=l1->next;
        l2=l2->next;
        while(l1!=NULL&&l2!=NULL)
        {
            ListNode* CurrentNode=new ListNode(l1->val+l2->val);
            newNode->next=CurrentNode;
            newNode=newNode->next;
            CurrentNode->next=NULL;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL&&l2==NULL)
        {
            ListNode* CurrentNode=new ListNode(l1->val);
            newNode->next=CurrentNode;
            newNode=newNode->next;
            CurrentNode->next=NULL;
            l1=l1->next;
        }
        while(l1==NULL&&l2!=NULL)
        {
            ListNode* CurrentNode=new ListNode(l2->val);
            newNode->next=CurrentNode;
            newNode=newNode->next;
            CurrentNode->next=NULL;
            l2=l2->next;
        }
        ListNode* p=head;
        while(p!=NULL)
        {
            if(p->val>=10)
            {
                if(p->next!=NULL)
                {
                    p->next->val=p->next->val+(p->val)/10;
                    p->val=(p->val)%10;
                }
                else//这边就是所如果你最后一位还有进位，那么你又要一个新的结点了。
                {
                    ListNode* PP=new ListNode((p->val)/10);
                    p->next=PP;
                    PP->next=NULL;
                    p->val=(p->val)%10;
                }
            }
            p=p->next;
        }
        return head;
        
    }
};