class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0)return 0;
        int start=0;
        int end=height.size()-1;
        int total=0;
        int middle=0;
        while(start<end)
        {
            if(height[start]<height[end])
            {
                middle=max(height[start],middle);
                total=total+middle-height[start];
                start++;
            }
            else
            {
                middle=max(height[end],middle);
                total=total+middle-height[end];
                end--;
            }
        }
        return total;
        
    }
};