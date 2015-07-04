class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256,-1);
        int maxLen=0;
        int index=-1;
        for(int i=0;i<s.length();i++)
        {
            if(hash[s[i]]>index)//如果当前字符出现过，那么当前子串的起始位置为这个字符上一次出现的位置+1
            {
                index=hash[s[i]];
            }
            if(i-index>maxLen)
            {
                maxLen=i-index;
            }
            hash[s[i]]=i;
        }
        return maxLen;
        
    }
};