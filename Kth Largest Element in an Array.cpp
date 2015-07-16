class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()<=0||k>nums.size()||k<=0) return 0;
        multiset<int> bst;
        for(int i=0;i<k;i++)//先进去k个数
        {
            bst.insert(nums[i]);
        }
        auto it=bst.begin();
        for(int i=k;i<nums.size();i++)
        {
            if(*it<nums[i])//和最小的那个数进行比较
            {
                bst.erase(it);
                bst.insert(nums[i]);
            }
            it=bst.begin();
        }
        return *it;
        
    }
};