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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int> > vec;
        vector<int> vec1;
        vec.clear();
        vec1.clear();
        if(root==NULL)
        {
            return vec;
        }
        que.push(root);
        int len=que.size();
        while(len!=0)
        {
            while(len--)
            {
                TreeNode* pNode=que.front();
                que.pop();
                vec1.push_back(pNode->val);
                if(pNode->left!=NULL)
                {
                    que.push(pNode->left);
                }
                if(pNode->right!=NULL)
                {
                    que.push(pNode->right);
                }
            }
            len=que.size();
            if(vec1.size()>0)
            {
                vec.push_back(vec1);
            }
            vec1.clear();
        }
        int i=0;
        len=vec.size()-1;
        vec1.clear();
        while(i<=len)
        {
            vec1=vec[i];
            vec[i]=vec[len];
            vec[len]=vec1;
            i++;
            len--;
        }
        return vec;
    }
};