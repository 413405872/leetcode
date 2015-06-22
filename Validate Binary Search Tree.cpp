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
private:
    vector<TreeNode*> vec;
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL)return true;
        if(root->left==NULL&&root->right==NULL)return true;
        inorder(root);
        for(int i=1;i<vec.size();i++)
        {
            if((vec[i-1])->val>=(vec[i])->val)
                return false;
        }
        return true;
    }
    void inorder(TreeNode* root)
    {
        if(root==NULL)return;
        inorder(root->left);
        vec.push_back(root);
        inorder(root->right);
    }
};