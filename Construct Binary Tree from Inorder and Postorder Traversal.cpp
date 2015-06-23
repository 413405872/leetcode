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
    
    TreeNode* ToTree(vector<int>& preO,int pSta,int pEnd,vector<int>& inO,int iSta,int iEnd)
    {
        if(pSta>pEnd||iSta>iEnd)return NULL;
        TreeNode* root=new TreeNode(preO[pEnd]);
        if(pSta==pEnd)return root;
        int i=0;
        for(i=iSta;i<=iEnd;i++)
        {
            if(inO[i]==preO[pEnd])
                break;
        }
        if(i>iEnd)return NULL;
        int ileftEnd=i-1;                              
        int irightStart=i+1;                                    
        int pleftEnd=pSta+i-iSta-1;                               
        int prightStart=pleftEnd+1;                            
        root->left=ToTree(preO,pSta,pleftEnd,inO,iSta,ileftEnd);
        root->right=ToTree(preO,prightStart,pEnd-1,inO,irightStart,iEnd);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& preorder) {
        if(preorder.size()<=0||inorder.size()<=0||preorder.size()!=inorder.size())
            return NULL;//前缀和中缀一定要个数相同且长度不为0
        TreeNode* pRoot=ToTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
		return pRoot;
        
    }
};