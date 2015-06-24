class Solution {
public:
    void scanDigits(string& s,int& i)//浏览0到9的数字
    {
        while(i<s.length()&&s[i]>='0'&&s[i]<='9')
            i++;
    }
    bool isExp(string& s,int& i)//判断e后面的数是否合法
    {
        i++;//因为第一个已经判断过是e或者E了;
		if(i<s.length()&&s[i]=='+'||s[i]=='-')
            i++;
        if(i==s.length())return false;//你不能说最后一个就直接是e或者符号吧
        scanDigits(s,i);
        return (i==s.length())? true:false;
    }
	void clearBlank(string& s)//先去掉字符串的空格
	{
		if(s.length()==0)return;
		int i=0;
		while(s.length()>0&&s[0]==' ')
		{
			s.erase(0,1);
		}
		while(s.length()>0&&s[s.length()-1]==' ')
		{
			s.erase(s.length()-1,1);
		}
	}
    bool isNumber(string s) {
		clearBlank(s);//先把空格给去掉
        if(s.length()<=0)return false;
        int i=0;
        int len=s.length();
		if(len==1&&s[i]=='.')
			return false;
        if(s[i]=='+'||s[i]=='-')
		{
            i++;
			if(len==2&&s[i]=='.')
				return false;
		}
        if(i==len)
            return false;
        bool numeric=true;
        scanDigits(s,i);//这个是先遍历这个前面的数字
        if(i<len)
        {
            if(s[i]=='.')
            {
				i++;
				scanDigits(s,i);
				if(i==1&&(s[i]=='e'||s[i]=='E')&&s[i-1]=='.')
					numeric=false;
				else if(i<len&&(s[i]=='e'||s[i]=='E'))
					numeric=isExp(s,i);
            }
            else if(i<len&&(s[i]=='e'||s[i]=='E'))
            {
				if(i==0||(i==1&&(s[i-1]=='+'||s[i-1]=='-')))//这个就是说你第一个字符就是e,或者第一个字符是符号，第二个字符是e.那肯定是不行的
					numeric=false;
				else
	                numeric=isExp(s,i);
            }
            else
            {
                numeric=false;//你说你前面既不是小数点，又不是e，那么数字访问完了还没有到结尾，那只能是false了
            }
        }
        return (i==len)&&numeric;
        
    }
};