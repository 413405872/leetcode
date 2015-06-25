class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        long long temp=0;
        int x_copy=x;
        while(x!=0)
        {
            int n=x%10;
            temp=temp*10+n;
            x=x/10;
        }
        if(temp>=INT_MAX)return false;
        if(temp==x_copy)return true;
        return false;
        
    }
};