class Solution {
public:
    string getPermutation(int n, int k) {  
        if(n<=0||k<=0)return "";
		int ntan=1;
		vector<int> vec(n,0);
		for(int i=0;i<n;i++)
		{
			vec[i]=i+1;
			ntan*=(i+1);
		}
		string back="";
		k--;
		for(int i=0;i<n;i++)
		{
			ntan=ntan/(n-i);//这个就是n的阶乘
			int kSel=k/ntan;
			back+=(vec[kSel]+'0');//这个就是按顺序将第一到最后一个字符入串
			for(int j=kSel;j<n-1-i;j++)//这个一定要减去一个i，因为最后一个字符已经没有用了
				vec[j]=vec[j+1];
			k=k%ntan;
		}
		return back;
    }
};