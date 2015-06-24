class Solution {
public:
    int mySqrt(int x) {
        //牛顿方法
       if (x == 0) return 0;  
        double xi1 = x, xi = 1;  
        while (int(xi1) != int(xi))  
        {  
            xi = xi1;  
            xi1 = (double(x)/xi + xi)/2;  
        }  
        return xi;
        
    }
};