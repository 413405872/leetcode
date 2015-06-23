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
    vector<int> vec;//千万不要定义成局部变量    
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > back;
        pathSum(root,back,sum,0);
        return back;
    }
    void pathSum(TreeNode* root,vector<vector<int> >& back,int sum,int curSum)
    {
        if(root==NULL)return;
        curSum+=root->val;
        vec.push_back(root->val);
        bool isLeaf=(root->left==NULL&&root->right==NULL);
        if(curSum==sum&&isLeaf)
        {
            back.push_back(vec);
        }
        if(root->left!=NULL)pathSum(root->left,back,sum,curSum);
        if(root->right!=NULL)pathSum(root->right,back,sum,curSum);
        vec.pop_back();
    }
};