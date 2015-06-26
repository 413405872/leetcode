class Solution {
public:
    int titleToNumber(string s) {
        if(s.length()<=0)return 0;
        int back=0;
        for(int i=0;i<s.length();i++)
        {
            back=back*26+(s[i]-'A')+1;
        }
        return back;
        
    }
};