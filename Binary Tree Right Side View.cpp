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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vec;
        vector<int> back;
        back.clear();
        back.clear();
        queue<TreeNode*> que;
        if(root==NULL)
        {
            return back;
        }
        que.push(root);
        int len=que.size();
        while(len!=0)
        {
            while(len--)
            {
                TreeNode* pNode=que.front();
                que.pop();
                vec.push_back(pNode->val);
                if(pNode->right!=NULL)
                {
                    que.push(pNode->right);
                }
                if(pNode->left!=NULL)
                {
                    que.push(pNode->left);
                }
            }
            len=que.size();
            if(vec.size()>0)
            {
                back.push_back(vec[0]);
            }
            vec.clear();
        }
        return back;
        
    }
};