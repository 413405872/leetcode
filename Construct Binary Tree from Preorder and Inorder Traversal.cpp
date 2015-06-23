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
        TreeNode* root=new TreeNode(preO[pSta]);//前缀的第一个结点就是二叉树的根结点
        if(pSta==pEnd)return root;//当这边就一个节点的时候就不要再往下跑了
        int i=0;
        for(i=iSta;i<=iEnd;i++)
        {
            if(inO[i]==preO[pSta])
                break;
        }//这是后出来的i就是中序中根结点所在的位置
        if(i>iEnd)return NULL;//就是在前序中有的在中序中没有找到
        int ileftEnd=i-1;                              //中序的左边的结束，左边开始是iSta
        int irightStart=i+1;                                    //中序的右边的开始，右边结束是iEnd
        int pleftEnd=pSta+i-iSta;                               //前序的左边的结束，左边开始是pSta+1
        int prightStart=pleftEnd+1;                            //前序右边的开始，右边的解释是pEnd;
        root->left=ToTree(preO,pSta+1,pleftEnd,inO,iSta,ileftEnd);//左边
        root->right=ToTree(preO,prightStart,pEnd,inO,irightStart,iEnd);//右边
        return root;
    }

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()<=0||inorder.size()<=0||preorder.size()!=inorder.size())
            return NULL;//前缀和中缀一定要个数相同且长度不为0
        TreeNode* pRoot=ToTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
		return pRoot;
    }
};