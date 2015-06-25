class Solution {
public:
    bool equal(double num1,double num2)
    {
        if(num1-num2<0.0000001&&num1-num2>-0.0000001)
            return true;
        return false;
    }
    double Power(double base, int expo)
    {
        if(expo==0)
            return 1.0;
        if(expo==1)
            return base;
        double result=Power(base,expo/2);
        result*=result;
        if(expo%2==1)
            result*=base;
        return result;
    }
    double myPow(double x, int n) {
        if(equal(x,0.0)&&n<0)return 0.0;//这里如果x为0，n是不能为负数的
        bool minus=false;
        if(n<0)
        {
            minus=true;
            n=0-n;
        }
        double result=Power(x,n);
        if(minus)
            result=1.0/result;
        return result;
        
    }
};