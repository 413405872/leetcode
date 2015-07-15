class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int len=nums.size();
        if(len<=1||k==0) return false;//这里K=0的情形也会出现
        multiset<long long> bst;//注意这里不能用set，set是不允许有重复元素的
        for(int i = 0;i<len;i++)
        {
            if(bst.size()==k+1)
                bst.erase(nums[i-k-1]);//这个时候把第一个进来的给去掉，因为他已经不满足|i-j|<=k了
			bst.insert(nums[i]);
            if(i>0)
            {
                auto lb=bst.lower_bound(nums[i]);//找到这个数所处的位置，因为set它是按从小到大排列的，如果它比左右都大，其他的就不用比较了啊
				if(lb!=bst.begin()&&lb!=--bst.end())//这个是在中间找到
				{
					auto llb=--lb;
					lb++;
					if(abs(*lb-*llb)<=t) return true;//与前一个比较
					llb=++lb;
					lb--;
					if(abs(*lb-*llb)<=t) return true;//与后一个比较
				}
				else if(lb==bst.begin())
				{
					auto llb=++lb;
					lb--;
					if(abs((*lb)-(*llb))<=t) return true;//与后一个比较
				}
				else
				{
					auto llb=--lb;
					lb++;
					if(abs(*lb-*llb)<=t) return true;//与前一个比较
				}
            }
        }
        return false;
        
    }
};