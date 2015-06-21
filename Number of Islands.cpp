class Solution {
public:
    void IslandsDFS(vector<vector<char> >& grid,vector<vector<bool> >& visit,int i,int j)
    {
        if(i<0||i>=grid.size())//如果行数越界那返回
            return ;
        if(j<0||j>=grid[0].size())//如果列数越界那返回
            return ;
        if(grid[i][j]!='1'||visit[i][j])//访问到0或者该点已经访问过那返回
            return ;
        visit[i][j]=true;//如果上述都不行，那么说明是1，且连通了
        IslandsDFS(grid,visit,i-1,j);//上边
        IslandsDFS(grid,visit,i+1,j);//下边
        IslandsDFS(grid,visit,i,j-1);//左边
        IslandsDFS(grid,visit,i,j+1);//右边
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0||grid[0].size()==0)
            return 0;
        int i=grid.size();
        int j=grid[0].size();
        int numIsland=0;
        vector<vector<bool> >visit(i,vector<bool>(j,false));
        for(int x=0;x<i;x++)
        {
            for(int y=0;y<j;y++)
            {
                if(grid[x][y]=='1'&&!visit[x][y])//进去以后一次结束就是一个连通区域
                {
                    IslandsDFS(grid,visit,x,y);
                    numIsland++;
                }
            }
        }
        return numIsland;
    }
};