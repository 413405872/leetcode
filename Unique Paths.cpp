class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==0||n==0)return 0;
        if(m==1||n==1)return 1;
        vector<vector<int> > back(m,vector<int>(n,0));
        for(int i=0;i<n;i++)//第一行
        {
            back[0][i]=1;
        }
        for(int i=0;i<m;i++)//第一列
        {
            back[i][0]=1;
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                back[i][j]=back[i-1][j]+back[i][j-1];
            }
        }
        return back[m-1][n-1];
    }
};