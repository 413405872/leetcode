class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()<=0||nums[0]>target)return 0;
        if(nums[nums.size()-1]<target)return nums.size();
        //接下来要处理的就是target它肯定在0-(nums.size()-1)范围内
        int i=0;
        int j=nums.size()-1;
        while(i<=j&&i<nums.size()&&j<nums.size())
        {
            int mid=(i+j)/2;
            if(target==nums[mid])return mid;
            else if(target<nums[mid])j=mid-1;
            else i=mid+1;
        }
        return i;
        
    }
};