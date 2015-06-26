class Solution {
public:
     string fractionToDecimal(int numerator, int denominator) {
         string ans = "";  
         long long nume = numerator;  
         long long deno = denominator;  
         if(denominator == 0)return ans;  
         if(numerator == 0) return "0";  
         if(denominator < 0 ^ numerator < 0) {  
            ans += '-';  
            nume = abs(nume);  
            deno = abs(deno);  
         }  
         ans += to_string(nume / deno);  
         long long rem = nume % deno * 10;  
         if(rem == 0) return ans;  
         ans += '.';  
         map<long long,int> m;  
         long long res = 0;  
         while(rem){  
            if(m.find(rem) != m.end()){  
                int begin = m[rem];  
                string s1 = ans.substr(0,begin);  
                string s2 = ans.substr(begin);  
                ans = s1 + '(' + s2 + ')';  
                break;  
            }  
            m[rem] = ans.length();  
            res = rem / deno;  
            ans += to_string(res);  
            rem = rem % deno * 10;  
         }  
         return ans;    
    }
};