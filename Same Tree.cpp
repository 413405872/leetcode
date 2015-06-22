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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL)return true;//如果你来的结点都是空那返回true没问题
        if((p==NULL&&q!=NULL)||(p!=NULL&&q==NULL))return false;//不相同很好判断
        if(p->val!=q->val)return false;//值不相等的时候肯定也是false
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
        
    }
};