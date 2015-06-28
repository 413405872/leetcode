class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > back;
        vector<int> vec;
        vec.clear();
        back.push_back(vec);
        if(nums.size()<=0)return back;
        sort(nums.begin(),nums.end());//因为它要求非递减
        for(int i=1;i<=nums.size();i++)
        {
            subset(nums,back,vec,i,0);//这里第四个参数是每次进几个
        }
        return back;
    }
    void subset(vector<int> nums,vector<vector<int> >& back,vector<int>& vec,int number,int start)
    {
        if(number==vec.size())
        {
            back.push_back(vec);
            return;
        }
        for(int i=start;i<nums.size();i++)
        {
            vec.push_back(nums[i]);
            subset(nums,back,vec,number,i+1);
            vec.pop_back();
        }
    }
};