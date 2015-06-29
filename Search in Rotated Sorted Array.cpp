class Solution {
public:
    int minIndex(vector<int>&nums)//用二分法找到最小值的下标
    {
        int i=0;
        int j=nums.size()-1;
        while(i!=j)
        {
            int mid=(i+j)/2;
            if(nums[mid]>nums[j])i=mid+1;
            else j=mid;
            if(i==j-1)
            {
                return nums[i]>nums[j]?j:i;
            }
        }
        return i;
    }
    int Find(vector<int>& nums,int start,int end,int target)//用二分法找到一个递增数组中的target
    {
        if(start>end)return -1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]<target)start=mid+1;
            else end=mid-1;
        }
        return -1;
        
    }
    int search(vector<int>& nums, int target) {
        if(nums.size()<=0)return -1;
        int i=0;
        int j=nums.size()-1;
        int key=minIndex(nums);//这是最小值的下标
        int a1=0;
        int a2=0;
        a1=Find(nums,0,key-1,target);
        a2=Find(nums,key,nums.size()-1,target);
        return a1==-1?a2:a1;
        
    }
};