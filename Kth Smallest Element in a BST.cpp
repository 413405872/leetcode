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
    int back=INT_MIN;
    void Inorder(TreeNode *root, int *count,int k)
    {
        if(root==NULL||back!=INT_MIN)
            return;
        Inorder(root->left,count,k);
        (*count)++;
        if((*count)==k)
        {
            back=root->val;
            return;
        }
        Inorder(root->right,count,k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL)
            return 0;
        int count = 0;
        int val;
        Inorder(root, &count, k);
        return back;
    }
};