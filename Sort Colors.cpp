class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size()<=0)return;
        vector<int>::iterator start=nums.begin();
        vector<int>::iterator end=nums.end();
		end--;
        while(start!=nums.end()&&*start==0)//找到第一个不是0的
        {
            start++;
        }
        while(*end==2)//找到第一个不是2的
        {
            end--;
        }
        vector<int>::iterator run=start;
        while(run!=nums.end()&&end!=nums.end()&&run<=end)
        {
            if(*run==2)//这个肯定是先和2比，因为我run是不从0的地方开始的
            {
                swap(*run,*end);
                end--;
                while(end>start&&*end==2)//而且end为2时自己要向前走
                    end--;
            }
            if(*run==0)
            {
                swap(*run,*start);
                start++;
            }
            run++;
        }
    }
};