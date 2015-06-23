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
    void flatten(TreeNode* root) {
        if(root==NULL)return;
        stack<TreeNode*> sta;
        sta.push(root);
        while(!sta.empty())//前序遍历
        {
            TreeNode* pTemp=sta.top();
            sta.pop();
            if(pTemp->right!=NULL)sta.push(pTemp->right);
            if(pTemp->left!=NULL)sta.push(pTemp->left);
            pTemp->left=NULL;
            if(!sta.empty())
            {
                pTemp->right=sta.top();
            }
        }
    }
    
};