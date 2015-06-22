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
    bool hasPathSum(TreeNode* root, int sum) {
        return hasPathSum(root,sum,0);
    }
    bool hasPathSum(TreeNode* root,int sum,int curSum)
    {
        if(root==NULL)return false;
        curSum+=root->val;
        bool bLeft=false,bRight=false;
        bool isLeaf=(root->left==NULL&&root->right==NULL);
        if(sum==curSum&&isLeaf)return true;//和相等，且是叶子结点那么返回true
        if(root->left!=NULL)bLeft=hasPathSum(root->left,sum,curSum);
        if(root->right!=NULL)bRight=hasPathSum(root->right,sum,curSum);
        return bLeft||bRight;
    }
};