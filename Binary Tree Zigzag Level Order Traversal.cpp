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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > back;
        vector<int> vec;
        queue<TreeNode*>que;
        vec.clear();
        back.clear();
        if(root==NULL)
        {
            return back;
        }
        int i=0;
        que.push(root);
        int len=que.size();
        while(len!=0)
        {
            while(len--)
            {
                TreeNode* pNode=que.front();
                que.pop();
                vec.push_back(pNode->val);
                if(pNode->left!=NULL)
                    que.push(pNode->left);
                if(pNode->right!=NULL)
                    que.push(pNode->right);
            }
            len=que.size();
            if(i==1&&vec.size()>0)
            {
                reverse(vec.begin(),vec.end());
            }
            if(vec.size()>0)
            {
                back.push_back(vec);
            }
            i=1-i;
            vec.clear();//这一句是肯定要有的
        }
        
    }
};