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
    ListNode* getMiddleNode(ListNode* head){//寻找一个链表的中间节点
        ListNode* pNode1=head;
        ListNode* pNode2=head;
        int n=0;
        while(pNode1!=NULL)//获取整个链表的长度
        {
            pNode1=pNode1->next;
            n++;
        }
        int i=0;
        while(n/2-1>i)//找到这个链表的中点
        {
            pNode2=pNode2->next;
            i++;
        }
        return pNode2;
    }
public:
    ListNode* megerSort(ListNode* head1,ListNode* head2){//对两个链表进行归并
        if(head1==NULL)
        {
            return head2;
        }
        if(head2==NULL)
        {
            return head1;
        }
        ListNode* newNode;
        if(head1!=NULL&&head2!=NULL)
        {
            if(head1->val<head2->val)
            {
                newNode=head1;
                head1->next=megerSort(head1->next,head2);
            }
            else
            {
                newNode=head2;
                head2->next=megerSort(head1,head2->next);
            }
        }
        return newNode;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode* middleNode=getMiddleNode(head);
        ListNode* pNext=middleNode->next;
        middleNode->next=NULL;
        return megerSort(sortList(head),sortList(pNext));
        
    }
};