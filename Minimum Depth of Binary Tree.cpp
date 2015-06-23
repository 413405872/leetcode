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
    int minDepth(TreeNode* root) {
        if(root==NULL)return 0;
        int minheight=INT_MAX;
        int height=0;
        minDepth(root,&minheight,height);
        return minheight;
    }
    void minDepth(TreeNode* root,int* minheight,int height)
    {
        if(root==NULL)return;
        height++;
        bool isLeaf=(root->left==NULL&&root->right==NULL);
        if(isLeaf)
        {
            if(height<*minheight)
                *minheight=height;
        }
        if(root->left!=NULL)minDepth(root->left,minheight,height);
        if(root->right!=NULL)minDepth(root->right,minheight,height);
        height--;
    }
};