class Solution {
public:
    int charToInt(char s)
    {
        int a=0;
        switch(s)
        {
            case 'I': a=1;break;
            case 'V': a=5;break;
            case 'X': a=10;break;
            case 'L': a=50;break;
            case 'C': a=100;break;
            case 'D': a=500;break;
            case 'M': a=1000;break;
            default: a=0;break;
        }
        return a;
    }
public:
    int romanToInt(string s) {
        int i=0;
        int len=s.length()-1;
        int Current=0;
        int Sum=0;
        int Temp=0;
        if(len<0)//空字符串
        {
            return 0;
        }
        for(i=len;i>=0;i--)//从后面往前
        {
            if(charToInt(s[i])==0)//有非法字符
            {
                return 0;
            }
            else
            {
                Current=charToInt(s[i]);//当前的字符;
                if(Current>=Temp)
                {
                    Sum+=Current;
                }
                else
                {
                    Sum-=Current;
                }
                Temp=Current;//它的后面一个，就是访问的前一次
            }
        }
        return Sum;
    }
};