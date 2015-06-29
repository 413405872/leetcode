class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size()<=1)return;
		int n=matrix.size();
        int temp=matrix[0][0];
        for(int i=0;i<n/2;i++)
        {
            for(int r=0;r<n-i*2-1;r++)
            {
                int temp=matrix[i][i];
                for(int j=i;j<n-i-1;j++)//第一列
                {
                    matrix[j][i]=matrix[j+1][i];
                }
                for(int j=i;j<n-i-1;j++)//最后一行
                {
                    matrix[n-i-1][j]=matrix[n-i-1][j+1];
                }
                for(int j=n-i-1;j>i;j--)//最后一列
                {
                    matrix[j][n-i-1]=matrix[j-1][n-i-1];
                }
                for(int j=n-i-1;j>i;j--)//第一行
                {
                    matrix[i][j]=matrix[i][j-1];
                }
                matrix[i][i+1]=temp;
            }
        }
        
    }
};