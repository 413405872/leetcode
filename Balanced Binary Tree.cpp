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
    bool isBalanced(TreeNode* root) {
       int height=0;
       return isBalanced(root,&height);
    }
    bool isBalanced(TreeNode* root,int* height)
    {
        if(root==NULL)
        {
            *height=0;
            return true;
        }
        int left,right;
        bool bLeft=isBalanced(root->left,&left);
        bool bRight=isBalanced(root->right,&right);
        if(bLeft&&bRight)
        {
            int diff=left-right;
            if(diff<=1&&diff>=-1)
            {
                *height=1+(left>right?left:right);
                return true;
            }
        }
        return false;
    }
};