class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int> > back(obstacleGrid.size(), vector<int>(obstacleGrid[0].size()));
        back[0][0]=obstacleGrid[0][0]==0?1:0;//就是说如果是障碍那你就为0
        if(obstacleGrid[0][0]==1)return 0;//开始的路都被堵死了
        if(obstacleGrid.size()==1)//1行
        {
            for(int i=0;i<obstacleGrid[0].size();i++)
            {
                if(obstacleGrid[0][i]==1)return 0;
            }
        }
        if(obstacleGrid[0].size()==1)//1列
        {
            for(int i=0;i<obstacleGrid.size();i++)
            {
                if(obstacleGrid[i][0]==1)return 0;
            }
        }
        for(int i=1;i<obstacleGrid[0].size();i++)
            back[0][i]=obstacleGrid[0][i]==0?back[0][i-1]:0;
        for(int i=1;i<obstacleGrid.size();i++)
            back[i][0]=obstacleGrid[i][0]==0?back[i-1][0]:0;
        for(int i=1;i<obstacleGrid.size();i++)
        {
            for(int j=1;j<obstacleGrid[i].size();j++)
            {
                if(obstacleGrid[i][j]==1)back[i][j]=0;
                else
                {
                    back[i][j]=back[i-1][j]+back[i][j-1];
                }
            }
        }
        return back[back.size()-1][back[0].size()-1];
    }
};