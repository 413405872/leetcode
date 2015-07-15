class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()<=0)return false;
        map<int,int> hash;
        for(int i=0;i<nums.size();i++)
        {
            hash[nums[i]]++;
            if(hash[nums[i]]>1)return true;//在统计过程中就可以进行判定了，只要有一次开始大于0了就true
        }
        return false;
        
    }
};