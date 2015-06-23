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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()<=0)return NULL;
        int len=nums.size();
        int start=0;
        int end=len-1;
        TreeNode* root=new TreeNode(nums[end/2]);
        root->left=ToBst(nums,start,end/2-1);
        root->right=ToBst(nums,end/2+1,end);
        return root;
    }
    TreeNode* ToBst(vector<int> nums,int start,int end)
    {
        if(start>end)return NULL;
        int middle=(start+end)/2;
        TreeNode* newNode=new TreeNode(nums[middle]);
        newNode->left=ToBst(nums,start,middle-1);
        newNode->right=ToBst(nums,middle+1,end);
        return newNode;
    }
};