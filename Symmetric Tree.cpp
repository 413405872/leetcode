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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;//直接空的话那就是对称的
        queue<TreeNode*> que1,que2;
        que1.push(root->left);
        que2.push(root->right);
        while(!que1.empty()&&!que2.empty())
        {
            TreeNode* pNode1=que1.front();
            TreeNode* pNode2=que2.front();
            que1.pop();
            que2.pop();
            if((pNode1==NULL&&pNode2!=NULL)||(pNode1!=NULL&&pNode2==NULL))return false;
            if(pNode1!=NULL&&pNode2!=NULL)
            {
                if(pNode1->val!=pNode2->val)return false;
                //执行下面就是说这两个值相等了
                que1.push(pNode1->left);
                que2.push(pNode2->right);
                que1.push(pNode1->right);
                que2.push(pNode2->left);
            }
        }
        return true;
    }
};