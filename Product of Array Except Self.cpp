class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> back;
        if(nums.size() <= 0)
            return back;
        int len = nums.size();
        back.push_back(1);
        for(int i = 1; i < len; i++)//先是a[0]...a[i-1]
        {
            back.push_back(back[i-1]*nums[i-1]);
        }
        int temp = 1;
        for(int i = len - 2; i >= 0; i--)//这边是a[i+1]****a[len-1]
        {
            temp *= nums[i+1];
            back[i] *= temp;
        }
        return back;
    }
};