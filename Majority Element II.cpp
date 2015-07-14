class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int len = nums.size();
        vector<int> back;
        int cou1 = 0, cou2 = 0;//计数，众数的个数
        int num1 = 0, num2 = 0;
        for(int i = 0; i < len; i++)//这个遍历选出众数
        {
            if(nums[i] == num1)
                cou1++;
            else if(nums[i] == num2)
                cou2++;
            else if(cou1 == 0)
            {
                num1 = nums[i];
                cou1 = 1;
            }
            else if(cou2 == 0)
            {
                num2 = nums[i];
                cou2 =1;
            }
            else
            {
                cou1--;
                cou2--;
            }
        }
        cou1 = 0;
        cou2 = 0;
        for(int i = 0; i< len; i++)
        {
            if(nums[i] == num1)
                cou1++;
            else if(nums[i] == num2)
                cou2++;
        }
        if(cou1 > len/3)
            back.push_back(num1);
        if(cou2 > len/3)
            back.push_back(num2);
        return back;
    }
};