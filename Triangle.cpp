class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int row=triangle.size();
        if(row==0)return 0;
        if(row==1)return triangle[0][0];
        vector<int> back=triangle[row-1];//取其最后一行
        for(int i=row-2;i>=0;i--)//倒数第二行开始
        {
            for(int j=0;j<=i;j++)
            {
                back[j]=triangle[i][j]+min(back[j],back[j+1]);
            }
        }
        return back[0];
    }
};