class Solution {
public:
    string addBinary(string a, string b) {
        int lenA=a.length()-1;
        int lenB=b.length()-1;
        string addAB;
        while(lenA>=0&&lenB>=0)//先求和然后放入新的String里面
        {
            addAB+=(a[lenA]-'0')+(b[lenB]-'0')+'0';
            lenA--;
            lenB--;
        }
        while(lenA>=0)//A还没结束
        {
            addAB+=a[lenA];
            lenA--;
        }
        while(lenB>=0)//B还没结束
        {
            addAB+=b[lenB];
            lenB--;
        }
        int lenAB=addAB.length()-1;//此时addAB中放的是倒序的。
        int i=0;
        int temp=0;
        while(i<=lenAB)//开始进位
        {
            temp=addAB[i]-'0';
            if(temp>=2)
            {
                addAB[i]=temp%2+'0';//先改自己的
                if(i==lenAB)//如果是最后一个那还要进位的。
                {
                    addAB+=(temp/2+'0');
                    break;
                }
                addAB[i+1]=((addAB[i+1]-'0')+temp/2)+'0';
            }
            i++;
        }
        char t;
        i=0;
        lenAB=addAB.length()-1;
        while(i<=lenAB)
        {
            t=addAB[i];
            addAB[i]=addAB[lenAB];
            addAB[lenAB]=t;
            i++;
            lenAB--;
        }
        return addAB;
        
    }
};