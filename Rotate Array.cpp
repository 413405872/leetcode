class Solution {
    void reverse(vector<int>& nums, int start,int end)
    {
        if(start>=end)return;
        while(start<end&&end<nums.size())
        {
            int temp=nums[start];
            nums[start]=nums[end];
            nums[end]=temp;
            start++;
            end--;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()<=0)return;
        if(k>nums.size())
            k=k%nums.size();
        if(k==0||k==nums.size())return;
        reverse(nums,0,nums.size()-1);//旋转整个
        reverse(nums,0,k-1);//旋转前k个
        reverse(nums,k,nums.size()-1);//旋转后面剩下的
    }
};