class Solution {
public:
    string getPostString(string s)//这个是中缀转后缀
{
	string back="";
	stack<char> op;
	int len=s.length();
	for(int i=0;i<len;i++)
	{
		switch(s[i])
		{
		case ' ':
			break;
		case'(':
			op.push(s[i]);
			break;
		case')':
			while(!op.empty()&&op.top()!='(')
			{
				back+=op.top();
				op.pop();
			}
			if(!op.empty()&&op.top()=='(')
				op.pop();
			break;
		case'+':
		case'-':
			while(!op.empty()&&op.top()!='(')
			{
				back+=op.top();
				op.pop();
			}
			op.push(s[i]);
			break;
		default:
			while(i<len&&s[i]>='0'&&s[i]<='9')
			{
				back+=s[i];
				i++;
			}
			back+='#';//这是一个数的分隔符
			i--;
			break;
		}
	}
	while(!op.empty())
	{
		back+=op.top();
		op.pop();
	}
	return back;
}
int calculate(string s) {
	string deal=getPostString(s);//得到后缀，然后开始入栈计算
	cout<<deal<<endl;
	stack<int> sta;
	int len=deal.length();
	int num1,num2,temp=0;
	for(int i=0;i<len;i++)
	{
		switch(deal[i]){
		case'+':
			num2=sta.top();
			sta.pop();
			num1=sta.top();
			sta.pop();
			sta.push(num1+num2);
			break;
		case'-':
			num2=sta.top();
			sta.pop();
			num1=sta.top();
			sta.pop();
			sta.push(num1-num2);
			break;
		case'#':
			break;
		default:
			while(i<len&&deal[i]>='0'&&deal[i]<='9')
			{
				temp=temp*10+(deal[i]-'0');
				i++;
			}//最终出来这个i肯定是一个#
			sta.push(temp);
			temp=0;
			break;
		}
	}
	return sta.top();
}
    
};