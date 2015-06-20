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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
        {
            return l2;
        }
        if(l2==NULL)
        {
            return l1;
        }
        ListNode* lNode1=l1;
        ListNode* lNode2=l2;
        ListNode* newhead;
        if(lNode1!=NULL&&lNode2!=NULL)
        {
            if(lNode1->val>lNode2->val)//l2小，所以头结点
            {
                newhead=lNode2;
                lNode2->next=mergeTwoLists(lNode1,lNode2->next);
            }
            else//l1小，所以头结点
            {
                newhead=lNode1;
                lNode1->next=mergeTwoLists(lNode1->next,lNode2);
            }
        }
        return newhead;
        
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {//这算是二分法吧
        int length=lists.size();
        if(length<1)
        {
            return NULL;
        }
        int count=1;
        while(length>1)//合并的链表个数要大于1个
        {
            for(int i=0;i<lists.size()-count;i=i+count*2)//count是*2增长的，可以将k举例大一点就可以看出来
            {
                lists[i]=mergeTwoLists(lists[i],lists[i+count]);
            }
            count=count*2;
            length=length/2+length%2;
        }
        return lists[0];
    }
};