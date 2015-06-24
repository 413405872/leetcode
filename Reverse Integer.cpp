class Solution {
public:
    int reverse(int x) {
        bool minus=false;
        if(x==INT_MIN)return 0;
        if(x<0)
        if(x<0)
            minus=true;
        long long back=0;
        long long fx=abs(x);
        while(fx!=0)
        {
            long long t=fx%10;
            back=back*10+t;
            fx=fx/10;
        }
        if(back>INT_MAX&&!minus)return 0;
        if(minus)
        {
            back=0-back;
            if(back<INT_MIN)
                return 0;
        }
        return back;
        
    }
};