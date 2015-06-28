class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size()<=0||matrix[0].size()<=0)return;
        int x=-1;
        int y=-1;
        bool firstBlood=false;
        for(int i=0;i<matrix.size();i++)//用这个找到第一个0记录下它的x,y下标，此时这个横轴，竖轴都没有用了
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(firstBlood&&matrix[i][j]==0)
                {
                    matrix[x][j]=0;
                    matrix[i][y]=0;
                }
                if(!firstBlood&&matrix[i][j]==0)//记下第一个为0的地方
                {
                    x=i;//行
                    y=j;//列
                    firstBlood=true;
                }
            }
        }
        if(x==-1)return;//表明没有0
        for(int i=0;i<matrix.size();i++)
        {
            if(i!=x&&matrix[i][y]==0)//对应的
            {
                for(int k=0;k<matrix[i].size();k++)//一行都搞为0
                    matrix[i][k]=0;
            }
        }
        for(int i=0;i<matrix.size();i++)//一行都搞为0
            matrix[i][y]=0;
        for(int i=0;i<matrix[x].size();i++)
        {
            if(i!=y&&matrix[x][i]==0)//对应的
            {
                for(int k=0;k<matrix.size();k++)//一列都搞为0
                    matrix[k][i]=0;
            }
        }
        for(int i=0;i<matrix[x].size();i++)//一列都搞为0
            matrix[x][i]=0;
    }
};