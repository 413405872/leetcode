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
    int getLeftCount(TreeNode* root)//获取左路节点个数
    {
        int count=0;
        while(root->left!=NULL)
        {
            root=root->left;
            count+=1;
        }
        return count;
    }
    int getRightCount(TreeNode* root)//获取右路节点个数
    {
        int count=0;
        while(root->right!=NULL)
        {
            root=root->right;
            count+=1;
        }
        return count;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        int l=getLeftCount(root)+1;
        int h=getRightCount(root)+1;
        if(l==h)//相等那就是满二叉树了
            return (1<<l)-1;
        else
            return 1+countNodes(root->left)+countNodes(root->right);
        
    }
};