class Solution {
public:
    int trailingZeroes(int n) {
        //n中5的个数肯定比2的个数少;
        int zeroNum=0;
        while(n!=0)
        {
            zeroNum+=n/5;
            n=n/5;
        }
        return zeroNum;
        
    }
};