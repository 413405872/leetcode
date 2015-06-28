class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > back;
        vector<int> vec;
        back.push_back(vec);
        if(nums.size()<=0)return back;
        sort(nums.begin(),nums.end());
        for(int i=1;i<=nums.size();i++)
        {
            subset(nums,back,vec,0,i);
        }
        return back;
    }
    void subset(vector<int>& nums,vector<vector<int> >& back,vector<int>& vec,int index,int number)
    {
        if(number==vec.size())
        {
            back.push_back(vec);
            return;
        }
        for(int i=index;i<nums.size();i++)
        {
            if(i!=index&&nums[i]==nums[i-1])
                continue;
            vec.push_back(nums[i]);
            subset(nums,back,vec,i+1,number);
            vec.pop_back();
        }
    }
};