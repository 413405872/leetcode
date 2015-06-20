/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL)
        {
            return NULL;
        }
        RandomListNode* pNode=head;
        RandomListNode* CopyHead=new RandomListNode(pNode->label);
        RandomListNode* newNode=CopyHead;
        while(pNode!=NULL)//这个就是先把所有结点都生成好，新结点原始结点的next
        {
            RandomListNode* pNext=pNode->next;
            pNode->next=newNode;
            newNode->next=pNext;
            pNode=pNext;
            if(pNode!=NULL)
            {
                RandomListNode* p=new RandomListNode(pNode->label);
                newNode=p;
                newNode->next=NULL;
                newNode->random=NULL;
            }
        }
        pNode=head;
        newNode=CopyHead;
        while(pNode!=NULL&&newNode!=NULL)//开始连接随机指针。
        {
            if(pNode->random!=NULL)//如果有随机指针
            {
                newNode->random=pNode->random->next;
            }
            pNode=newNode->next;
            if(pNode!=NULL)
            {
                newNode=pNode->next;
            }
        }
        //接下来的工作就是把这个两个链表拆分开
        pNode=head;
        newNode=CopyHead;
        while(pNode!=NULL&&newNode!=NULL)
        {
            pNode->next=newNode->next;
            pNode=pNode->next;
            if(pNode!=NULL)
            {
                newNode->next=pNode->next;
                newNode=newNode->next;
            }
        }
        return CopyHead;
        
    }
};