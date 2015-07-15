class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if(row<=0) return 0;
        int col = matrix[0].size();
        if(col<=0) return 0;
        vector<vector<int> > vec(row,vector<int>(col,0));
        int maxBoard=0;
        for(int i = 0;i < row;i++)//处理第一列
        {
            if(matrix[i][0]=='1')
            {
                vec[i][0]=1;
                maxBoard=1;
            }
        }
        for(int i = 0;i < col;i++)//处理第一行
        {
            if(matrix[0][i]=='1')
            {
                vec[0][i]=1;
                maxBoard=1;
            }
        }
        for(int i = 1; i < row; i++)
        {
            for(int j = 1; j < col; j++)
            {
                if(matrix[i][j] == '1')//这个是正方形的右下角;如果不为0那么默认为0
                {
                    vec[i][j]=min(vec[i-1][j-1],min(vec[i-1][j],vec[i][j-1]))+1;//这里有三个方向,自己还有一个方向
                    maxBoard=max(vec[i][j],maxBoard);
                }
            }
        }
        return maxBoard*maxBoard;
    }
};