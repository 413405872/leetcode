class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int,vector<int> > hash;//加入我有一个1,2,3,4,4那么我现在要算8，你是不是得4+4，所以用vector<int>
        vector<int> vec;
        vec.clear();
        if(numbers.size()<=1)return vec;
        for(int i=0;i<numbers.size();i++)
        {
            hash[numbers[i]].push_back(i);
        }
        map<int,vector<int> >::iterator it1=hash.begin();
        map<int,vector<int> >::iterator it2=--hash.end();
        while(vec.empty()&&it1!=it2)
        {
            int temp=it1->first+it2->first;
            if(temp==target)
            {
                if(it1->second.front()>it2->second.front())
                {
                    vec.push_back(it2->second.front()+1);
                    vec.push_back(it1->second.front()+1);
                }
                else
                {
                    vec.push_back(it1->second.front()+1);
                    vec.push_back(it2->second.front()+1);
                }
            }
            else if(temp>target)it2--;
            else it1++;
        }
        if(vec.empty()&&it1!=hash.end())
        {
            if(it1->second.size()>=2&&it1->first*2==target)
            {
                vec.push_back(it1->second.front()+1);
                vec.push_back((it1->second)[1]+1);
            }
        }
        return vec;
        
    }
};