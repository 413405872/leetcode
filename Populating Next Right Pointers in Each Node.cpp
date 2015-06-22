/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
//这一题提示了说是很好的二叉树所以用深度搜索比较好，当然这一题也可以用广度搜索，但是空间就不是常数,但深度其实也不是常数的，对数
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL)return;
        TreeLinkNode *pNode = root;
        while(pNode&&pNode->left&&pNode->right)
        {
            root=pNode;
            while(root)
            {
                root->left->next=root->right;     //同一个父亲的两个孩子在操作
                if(root->next){
                    root->right->next=root->next->left;   //同一个祖父的在操作
                }
                root=root->next;    //这个是同一行
            }
            pNode=pNode->left;//这个是不同的列
        }
    }
};