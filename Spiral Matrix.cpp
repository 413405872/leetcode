class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> back;
        if(matrix.size()<=0||matrix[0].size()<=0)return back;
        int row=matrix.size();
        int col=matrix[0].size();
        if(row==1||col==1)//1行或者1列的
        {
            for(int i=0;i<row;i++)
                for(int j=0;j<col;j++)
                    back.push_back(matrix[i][j]);
            return back;
        }
		int r=(row>col?col:row)-1;
        r=r/2;//这是旋转的圈数
        for(int i=0;i<=r;i++)
        {
            for(int j=i;j<col-1-i;j++)//第一行
                back.push_back(matrix[i][j]);
            for(int j=i;j<row-1-i;j++)//最后一列
                back.push_back(matrix[j][col-1-i]);
            for(int j=col-1-i;j>i;j--)//最后一行
                back.push_back(matrix[row-1-i][j]);
            for(int j=row-1-i;j>i;j--)//第一列
                back.push_back(matrix[j][i]);
			if(i==col-1-i&&i==row-1-i)//这个最后一个的时候没有走到
				back.push_back(matrix[i][i]);
        }
		return back;
    }
};