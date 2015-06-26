class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==0) return INT_MAX;
        long long divid=dividend, divis=divisor;
        if(dividend<0)divid=-divid;
        if(divisor<0)divis=-divis;
        
        long long res=0;
        if(divis==1)
        {
            res=divid;
            return (dividend<0^divisor<0)? -res:(res>=INT_MAX?INT_MAX:res);
        }
        while(divid>=divis)
        {
            long long temp=divis;
            int i;
            for(i=1;temp<=divid;i++)//找到第一个大于divid的数为止
            {    
                temp<<=1;
            }
            res+=(1<<(i-2));//上面出来后i至少等于2
            divid-=(divis<<(i-2));
        }
        return (dividend<0^divisor<0)? -res:(res>=INT_MAX?INT_MAX:res);
        
    }
};