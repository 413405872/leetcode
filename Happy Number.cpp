class Solution {
public:
    bool isHappy(int n) {
        if(n<=0)return false;
        vector<int> hash(10,0);
        map<int,int> hash1;
        for(int i=0;i<hash.size();i++)
            hash[i]=i*i;
        int temp=0;
        hash1[n]++;
        while(n!=1)
        {
            while(n!=0)
            {
                int k=n%10;
                temp+=hash[k];
                n=n/10;
            }
            n=temp;
            hash1[n]++;
            if(hash1[n]>=2)//这个就进入无限循环了
            {
                return false;
            }
            temp=0;
        }
        return true;
        
    }
};