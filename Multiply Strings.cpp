class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.length()<=0||num1.length()<=0)return "";
        if(num1.length()==1&&num1[0]=='0')return "0";
        if(num2.length()==1&&num2[0]=='0')return "0";
        vector<int> vec(num1.length()+num2.length()-1,0);
        string back="";
        for(int i=num1.length()-1;i>=0;i--)
        {
            for(int j=num2.length()-1;j>=0;j--)
            {
                vec[i+j]+=(num1[i]-'0')*(num2[j]-'0');
            }
        }
        for(int i=vec.size()-1;i>0;i--)
        {
            if(vec[i]>=10)
            {
                vec[i-1]+=(vec[i]/10);
                vec[i]=vec[i]%10;
            }
        }
        if(vec[0]>=10)
        {
            back+=(vec[0]/10+'0');
            vec[0]=vec[0]%10;
        }
        for(int i=0;i<vec.size();i++)
        {
            back+=(vec[i]+'0');
        }
        return back;
        
        
    }
};