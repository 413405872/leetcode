class Solution {
public:
    string intToRoman(int num) {
        if(num<=0)return "";
        int Roman[13]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
		vector<string> vec;
		vec.push_back("M");
		vec.push_back("CM");
		vec.push_back("D");
		vec.push_back("CD");
		vec.push_back("C");
		vec.push_back("XC");
		vec.push_back("L");
		vec.push_back("XL");
		vec.push_back("X");
		vec.push_back("IX");
		vec.push_back("V");
		vec.push_back("IV");
		vec.push_back("I");
        string back="";
		for(int i=0;i<vec.size();i++)
        {
            if(Roman[i]>num)
                continue;
            else
            {
                for(int r=num/Roman[i];r>0;r--)
                {
                    back+=vec[i];
                }
                num=num%Roman[i];
                if(num==0)
                    break;
            }
        }
        return back;
        
    }
};