class Solution {
public:
    int myAtoi(string str) {
        //首先你看它返回的是一个int,所以就不谈大数了，如果是大数他是不能够返回int的。
        if(str.length()<=0)//字符为空什么的，那我只能返回0了。当然可以给个标志位
        {
            return 0;
        }
        bool isPositive=true;//初始状态下认为它是正的
        string sMAX="2147483647";
        string sMIN="2147483648";
        string total="";
        int sum=0;
        int pos=1;
        int i=0;
        while((0<str.length())&&!(str[0]=='+'||str[0]=='-'||(str[0]>='0'&&str[0]<='9')))//满足后面任何一个就表明是开始了
        {
            if(str[0]==' ')//记住了，前面只能有空格，不是空格那就是错的。
                str.erase(0,1);
            else
                return 0;
        }
        int len=str.length()-1;
        while(i<=len)//处理数字后面第一个非数字的字符。
        {
            if(i==0&&(str[i]=='+'||str[i]=='-'))
            {;}
            else if(!(str[i]>='0'&&str[i]<='9'))
            {
                str.erase(i,str.length()-i);
                break;
            }
            i++;
        }
        len=str.length()-1;//这样len就直接作为下标了
        i=0;
        while(len>=i)//这个用于先把数字给正常字符串，因为有可能越界
        {
            if(str[i]>='0'&&str[i]<='9')
            {
                total+=str[i];
            }
            else//这个里面有一个特殊情况就是第一位可能是”正负号“
            {
                if(i==0&&(str[i]=='+'||str[i]=='-'))
                {
                    isPositive=(str[i]=='+' ? true:false);
                }
                else
                {
                    return 0;//表示有非法输入
                }
            }
            i++;
        }
        len=total.length();
        int s1=sMAX.length();
        int s2=sMIN.length();
        if(isPositive&&(len>s1||(len==s1&&total>=sMAX)))//这两个if用于处理溢出值的。
        {
            return INT_MAX;
        }
        if(!isPositive&&(len>s2||(len==s2&&total>=sMIN)))
        {
            return INT_MIN;
        }
        i=len-1;
        while(i>=0)
        {
            sum+=(total[i]-'0')*pos;
            pos*=10;
            i--;
        }
        return (isPositive==true ? sum:(0-sum));
        
    }
};