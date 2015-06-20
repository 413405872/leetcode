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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL||head->next==NULL)
        {
            return NULL;
        }
        ListNode* pNode1=head;
        ListNode* pNode2=head->next->next;
        while(pNode1!=NULL&&pNode2!=NULL)//先找出有没有环，有换找出结点。
        {
            if(pNode1==pNode2)
            {
                break;
            }
            pNode1=pNode1->next;
            if(pNode2!=NULL)
            {
                pNode2=pNode2->next;
                if(pNode2!=NULL)
                {
                    pNode2=pNode2->next;
                }
            }
        }
        if(pNode1==NULL||pNode2==NULL)//没有环
        {
            return NULL;
        }
        int nCircleNode=1;
        pNode1=pNode1->next;
        while(pNode1!=NULL&&pNode2!=NULL&&pNode1!=pNode2)//算出环包围的结点数
        {
            pNode1=pNode1->next;
            nCircleNode++;
        }
        ListNode* pBeginCircle=head;
        ListNode* p1=head;
        while(nCircleNode>0)
        {
            p1=p1->next;
            nCircleNode--;
        }
        while(pBeginCircle!=p1)
        {
            pBeginCircle=pBeginCircle->next;
            p1=p1->next;
        }
        return pBeginCircle;
    }
};