/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* pRoot=NULL;
        if(head==NULL)
        {
            return pRoot;
        }
        if(head->next==NULL)
        {
            pRoot=new TreeNode(head->val);
            return pRoot;
        }
        int n=0;
        ListNode* pNode=head;
        while(pNode!=NULL)
        {
            n++;
            pNode=pNode->next;
        }
        pNode=head;
        ListNode* pBreak=head;
        for(int i=0;i<n/2&&pNode!=NULL;i++)
        {
            pBreak=pNode;
            pNode=pNode->next;
        }
        pBreak->next=NULL;
        pRoot=new TreeNode(pNode->val);
        pRoot->left=sortedListToBST(head);
        pRoot->right=sortedListToBST(pNode->next);
        return pRoot;
        
    }
};