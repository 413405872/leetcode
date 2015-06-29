class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()<=0||matrix[0].size()<=0)return false;//里面没有元素
        for(int i=0;i<matrix.size();i++)
        {
            int j;
            for(j=matrix[i].size()-1;j>=0;j--)
            {
                if(matrix[i][j]<target)
                    break;//比目标值小直接进入下一行
                else if(matrix[i][j]==target)
                    return true;//如果相等直接返回，如果比目标值大只要扫这一行扫完就OK
            }
            if(j<0)
                break;
        }
        return false;
        
    }
};