class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size()<=1)return false;
        map<int,int> hash;
        for(int i=0;i<nums.size();i++)
        {
            if(hash.find(nums[i])!=hash.end()&&i-hash[nums[i]]<=k)//首先你要出现过，然后你出现的地方和现在地方不能超过k
                return true;
            else
                hash[nums[i]]=i;//哈希表里放你的位置
        }
        return false;
    }
};