class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1||s.length()==0)
        {
            return s;
        }
        int len=s.length();
        if(len<=numRows)
        {
            return s;
        }
        string ConString="";
        vector<string> vec(numRows);
        for(int i=0;i<len;)//这里不能有i++
        {
            for(int j=0;j<numRows&&i<len;j++,i++)//正向走,这里面的i++千万不能忘记
            {
                vec[j]+=s[i];
            }
            for(int j=numRows-2;j>0&&i<len;j--,i++)//斜向上，去掉最后一个j=numRows和j=0；
            {
                vec[j]+=s[i];
            }
        }
        for(int i=0;i<numRows;i++)
        {
            ConString+=vec[i];
        }
        return ConString;
    }
};