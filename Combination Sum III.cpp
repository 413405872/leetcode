class Solution {
private:
    vector<vector<int> > back;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        int a[9]={1,2,3,4,5,6,7,8,9};
        vector<int> cand(a,a+9);
        vector<int> vec;
        comSum3(cand,vec,0,n,k);
        return back;
        
    }
    void comSum3(vector<int>& cand,vector<int>& vec,int index,int target,int k)
    {
        if(target==0&&vec.size()==k)
        {
            back.push_back(vec);
        }
        else
        {
            for(int i=index;i<cand.size();i++)
            {
                if(target>=cand[i])
                {
                    vec.push_back(cand[i]);
                    comSum3(cand,vec,i+1,target-cand[i],k);
                    vec.pop_back();
                }
            }
        }
    }
};