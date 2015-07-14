class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        string temp = "";
        vector<string> back;
        if(nums.size() <= 0)
            return back;
        int begin = nums[0];
        int end = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == end || nums[i] == end + 1)
                end = nums[i];
            else
            {
                back.push_back(ToStr(begin, end));//这个链接的是上一次的
                begin = nums[i];
                end = nums[i];
            }
        }
        back.push_back(ToStr(begin, end));//最后一次是没有被录进来的
        return back;
    }
    string ToStr(int begin, int end)
    {
        char buffer[50];
        if(begin == end)
            sprintf(buffer, "%d", begin);
        else
            sprintf(buffer, "%d->%d", begin, end);
        return string(buffer);
    }
};