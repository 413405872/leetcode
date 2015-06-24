class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long left=(A>E?A:E);//选最大的
        long long right=(C<G?C:G);//选最小的
        long long top=(D<H?D:H);//选最小的
        long long bottom=(B>F?B:F);//选最大的
        long long x=(right-left>0?right-left:0);//底边长度
        long long y=(top-bottom>0?top-bottom:0);//高
        long long common=x*y;//公共面积
        int AC=(C-A)*(D-B);
        int EG=(G-E)*(H-F);
        return AC+EG-common;
    }
};