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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL||headB==NULL)
        {
            return NULL;
        }
        ListNode* aNode=headA;
        ListNode* bNode=headB;
        int aCount=0;
        int bCount=0;
        int a_b=0;
        while(aNode!=NULL)//计算A链表的长度
        {
            aCount++;
            aNode=aNode->next;
        }
        while(bNode!=NULL)//计算B链表的长度
        {
            bCount++;
            bNode=bNode->next;
        }
        aNode=headA;
        bNode=headB;
        int i=0;
        while(aCount-bCount>i)//A长，A就先走a-b步
        {
            i++;
            aNode=aNode->next;
        }
        while(bCount-aCount>i)//B长，B就先走b-a步
        {
            i++;
            bNode=bNode->next;
        }
        while(aNode!=NULL&bNode!=NULL&&aNode!=bNode)//剩下的长度一样长，就一起走
        {
            aNode=aNode->next;
            bNode=bNode->next;
        }
        return aNode;
    }
};