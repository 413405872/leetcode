class Solution {
public:
    string convertToTitle(int n) {
        string back="";
        if(n<=0)return back;
		char ch;
        while(n!=0)
        {
            int temp=n%26;
			if(temp==0)//就是能够整除26
			{
				ch='Z';
				back.insert(0,1,ch);
				n=n/26-1;
				if(n==0)//证明最后一个26了
					break;
				continue;
			}
			else
				ch='A'+temp-1;
            back.insert(0,1,ch);
            n=n/26;
        }
        return back;
    }
};