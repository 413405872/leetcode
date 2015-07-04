class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<=0)return "";
        int start=0;//回文串开始的地方
        int maxLen=1;//最长回文串的长度
        for(int i=0;i<s.length();i++)//奇数个
        {
            int sta=i-1;
            int end=i+1;
            while(sta>=0&&end<s.length()&&s[sta]==s[end])
            {
                if(end-sta+1>maxLen)
                {
                    maxLen=end-sta+1;
                    start=sta;
                }
                sta--;
                end++;
            }
        }
        for(int i=0;i<s.length();i++)//偶数个
        {
            int sta=i;
            int end=i+1;
            while(sta>=0&&end<s.length()&&s[sta]==s[end])
            {
                if(end-sta+1>maxLen)
                {
                    maxLen=end-sta+1;
                    start=sta;
                }
                sta--;
                end++;
            }
        }
        return s.substr(start,maxLen);
        
    }
};