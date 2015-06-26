class Solution {
public:
    int countPrimes(int n) {
        if(n<=0)return 0;
        bool *isPrime=new bool[n];
        for(int i=0;i<n;i++)
        {
            isPrime[i]=true;
        }
        for(int i=2;i*i<n;i++)
        {
            if(!isPrime[i])continue;
            for(int j=i*i;j<n;j+=i)//这个就是2*2,2*3,2*4,....3*3,3*4,3*5....都为false从4为false跳过，5*5,5*6.....
            {
                isPrime[j]=false;
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) count++;
        }
        delete [] isPrime;
        return count;
        
    }
    
};