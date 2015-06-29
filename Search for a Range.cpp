class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> found(2,-1);
        if(nums.size()<=0||nums[0]>target||nums[nums.size()-1]<target)return found;
        int i=0;
        int j=nums.size()-1;
        int start=0;
        int end=0;
        while(i<=j)//找到第一个target的下标
        {
            int mid=(i+j)/2;
            if((mid==0&&nums[mid]==target)||(mid!=0&&nums[mid]==target&&nums[mid-1]!=target))
            {
                start=mid;
                break;
            }
            else if(nums[mid]>=target)
                j=mid-1;
            else
                i=mid+1;
        }
        i=0;j=nums.size()-1;
        while(i<=j)//找到第一个target的下标
        {
            int mid=(i+j)/2;
            if((mid==nums.size()-1&&nums[mid]==target)||(mid!=nums.size()-1&&nums[mid]==target&&nums[mid+1]!=target))
            {
                end=mid;
                break;
            }
            else if(nums[mid]>target)
                j=mid-1;
            else
                i=mid+1;
        }
        if(end==0&&nums[end]!=target)return found;
        found[0]=start;
        found[1]=end;
        return found;
        
    }
};