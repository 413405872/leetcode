class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> vec;
        vec.clear();
        if(digits.size()<=0)return vec;
        digits[digits.size()-1]+=1;
        for(int i=digits.size()-1;i>=0;i--)
        {
            if(digits[i]>=10)
            {
                if(i>0)
                {
                    digits[i-1]+=(digits[i]/10);
                    digits[i]=digits[i]%10;
                }
            }
        }
        for(int i=0;i<digits.size();i++)
        {
            if(digits[i]>=10)
            {
                vec.push_back(digits[i]/10);
                digits[i]%=10;
            }
            vec.push_back(digits[i]);
        }
        return vec;
        
    }
};