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
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;
        int maxHeight=0;
        int height=0;
        maxDepth(root,&maxHeight,height);
        return maxHeight;
    }
    void maxDepth(TreeNode* root,int* maxHeight,int height)
    {
        if(root==NULL)return;
        height++;//只要进来一个节点不为NULL，那高度就要加1了
        bool isLeaf=(root->left==NULL&&root->right==NULL);
        if(isLeaf)
        {
            if(*maxHeight<height)
                *maxHeight=height;
        }
        if(root->left!=NULL)maxDepth(root->left,maxHeight,height);
        if(root->right!=NULL)maxDepth(root->right,maxHeight,height);
        height--;
    }
};