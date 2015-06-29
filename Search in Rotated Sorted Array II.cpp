class Solution {
public:
    int minIndex(vector<int>&nums)
    {
        int i=0;
        int j=nums.size()-1;
        while(i!=j)
        {
            int mid=(i+j)/2;
			if(nums[i]==nums[j]&&nums[j]==nums[mid])//这种情况二分法搞不了
			{
				for(int k=i;k<j;k++)
				{
					if(nums[k]>nums[k+1])
						return k+1;
				}
				return i;
			}
            if(nums[mid]>nums[j])i=mid+1;
            else j=mid;
            if(i==j-1)
            {
                return nums[i]>nums[j]?j:i;
            }
        }
        return i;
    }
    bool Find(vector<int>& nums,int start,int end,int target)//用二分法找到一个递增数组中的target
    {
        if(start>end)return false;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(nums[mid]==target)return true;
            else if(nums[mid]<target)start=mid+1;
            else end=mid-1;
        }
        return false;
        
    }
    bool search(vector<int>& nums, int target) {
        if(nums.size()<=0)return -1;
        int i=0;
        int j=nums.size()-1;
        int key=minIndex(nums);//这是最小值的下标
        bool a1=0;
        bool a2=0;
        a1=Find(nums,0,key-1,target);
        a2=Find(nums,key,nums.size()-1,target);
        return a1||a2;
        
    }
};