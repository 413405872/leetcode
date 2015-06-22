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
    void recoverTree(TreeNode *root) {
         n1 = n2 = pre = NULL;
        inorder(root);
         if (n1 && n2) swap(n1->val, n2->val);
     }
     
    void inorder(TreeNode *root) {
        if (!root) return;
         inorder(root->left);
         if (pre && pre->val > root->val) {
            if (!n1) n1 = pre;
             n2 = root;
        }
         pre = root;
        inorder(root->right);
     }
     
 private:
     TreeNode *n1;
     TreeNode *n2;
    TreeNode *pre;
};