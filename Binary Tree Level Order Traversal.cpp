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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > vec;
		vector<int> vec1;
        if(root==NULL)
        {
            return vec;
        }
        queue<TreeNode*> que;
        TreeNode* pNode=root;
        que.push(pNode);
        int len=1;
        int i=0;
        while(len!=0)
        {
            while(len--)
            {
                TreeNode* pTemp=que.front();
                que.pop();
                vec1.push_back(pTemp->val);
                if(pTemp->left!=NULL)
                {
                    que.push(pTemp->left);
                }
                if(pTemp->right!=NULL)
                {
                    que.push(pTemp->right);
                }
            }
			if(vec1.size()>0)
				vec.push_back(vec1);
			vec1.clear();
            i++;
            len=que.size();
        }
        return vec;
    }
};