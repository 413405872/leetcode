class Solution {
public:
    int countDigitOne(int n) {
        if(n <= 0)
            return 0;
        char str[40];
        sprintf(str, "%d", n);
        return NumberOf1(str);
    }
    int NumberOf1(const char *str)
    {
        if(str == NULL || *str < '0' || *str > '9' || *str == '\0')
            return 0;
        int firstNum = *str-'0';
        int length = strlen(str);
        if(length == 1)//假如只有一个元素
            return firstNum == 0 ? 0 : 1;
        int firstDigit = 0;
        if(firstNum > 1)//最高位1的个数
            firstDigit = Power10(length - 1);
        else if(firstNum == 1)
            firstDigit = atoi(str + 1) + 1;
        int secondDigit = firstNum * (length - 1) * Power10(length - 2);
        int thirdDigit = NumberOf1(str + 1);
        return firstDigit + secondDigit + thirdDigit;
    }
    int Power10(int len)
    {
        int back = 1;
        for(int i = 0; i< len; i++)
            back *= 10;
        return back;
    }
};