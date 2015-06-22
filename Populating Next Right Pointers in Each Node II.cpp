/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL)return;
        queue<TreeLinkNode*> que;
        que.push(root);
        int len=que.size();
        while(len)
        {
            queue<TreeLinkNode*> qTemp;
            while(len--)
            {
                TreeLinkNode* pNode=que.front();
                que.pop();
                if(que.size()>0)
                {
                    pNode->next=que.front();
                }
                if(pNode->left!=NULL)qTemp.push(pNode->left);
                if(pNode->right!=NULL)qTemp.push(pNode->right);
            }
            que=qTemp;
            len=que.size();
        }
        
    }
};