class Solution {
public:
    vector<vector<int> > generateMatrix(int n)  
    {  
        vector<vector<int> > result(n,vector<int>(n,0));  
        int begin=0, end = n-1;  
        int num=1;  
        while(begin<end)  
        {  
            for(int j=begin;j<end;j++)
                result[begin][j]=num++;  
            for(int i=begin;i<end;i++)
                result[i][end]=num++;  
            for(int j=end;j>begin;j--)
                result[end][j]=num++;  
            for(int i=end;i>begin;i--)  
                result[i][begin]=num++;  
            begin++; 
            end--;  
        }  
        if(begin==end)  
            result[begin][end] = num;  
        return result;  
    }
};