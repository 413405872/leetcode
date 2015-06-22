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
//会不会出现很大的数，如果出现很大的数那就要用字符串进行处理
public:
    int sumNumbers(TreeNode* root) {
        if(root==NULL)return 0;
        vector<vector<int> >vec;
        vector<int>vec1;
        sumNumbers(root,vec,vec1);//这个执行完，那么vec中放了所有根到叶节点的路径.这样可以有助于处理大数的问题
        int sum=0;
        for(int i=0;i<vec.size();i++)
        {
            int curSum=0;
            for(int j=0;j<vec[i].size();j++)
            {
                curSum=curSum*10+vec[i][j];
            }
            sum=sum+curSum;
        }
        return sum;
        
        
    }
    void sumNumbers(TreeNode* root,vector<vector<int> >& vec,vector<int> vec1)
    {
        if(root==NULL)return;
        vec1.push_back(root->val);
        bool isLeaf=(root->left==NULL&&root->right==NULL);
        if(isLeaf)
        {
            vec.push_back(vec1);
        }
        if(root->left!=NULL)sumNumbers(root->left,vec,vec1);
        if(root->right!=NULL)sumNumbers(root->right,vec,vec1);
        vec1.pop_back();
    }
};