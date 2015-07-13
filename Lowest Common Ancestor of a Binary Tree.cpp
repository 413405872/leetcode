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
    stack<TreeNode*> stap;
    stack<TreeNode*> staq;
    bool PreOrder(TreeNode* root, TreeNode* Node, stack<TreeNode*>& sta, int *len)//入栈
    {
        if(root==NULL)
            return false;
        sta.push(root);
        (*len)++;
        if(root == Node)
            return true;
        if(PreOrder(root->left, Node, sta, len))
            return true;
        if(root != NULL && PreOrder(root->right, Node, sta, len))
            return true;
        sta.pop();
        (*len)--;
        return false;
        
    }
    TreeNode* CommonNode(stack<TreeNode*> stap, stack<TreeNode*> staq, int plen, int qlen)//找两个栈的公共结点
    {
        if(plen < qlen)
            return CommonNode(staq, stap, qlen, plen);
        while(plen > qlen)
        {
            stap.pop();
            plen--;
        }
        while(!stap.empty() && !staq.empty())
        {
            if(stap.top() == staq.top())
                return stap.top();
            stap.pop();
            staq.pop();
        }
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL||p==NULL||q==NULL)
            return NULL;
        TreeNode* pNode = root;
        int plen = 0, qlen = 0;
        PreOrder(pNode, p, stap, &plen);
        pNode = root;
        PreOrder(pNode, q, staq, &qlen);
        return CommonNode(stap, staq, plen, qlen);
    }
};