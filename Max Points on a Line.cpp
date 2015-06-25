/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.size()<=0)return 0;
        int maxPoint=0;
        for(int i=0;i<points.size();i++)
        {
            map<double,int> hash;
            int samePoint=0;
            double ratio=0.0;
            for(int j=i+1;j<points.size();j++)
            {
                if(points[j].x==points[i].x&&points[j].y==points[i].y)//同一点
                {
                    samePoint++;
                    continue;
                }
                else if(points[j].x==points[i].x)//斜率为无穷大
                    ratio=(double)INT_MAX;
                else if(points[j].y==points[i].y)//与x轴平行，斜率为0
                    ratio=0.0;
                else
                    ratio=(double)(points[j].y-points[i].y)/(points[j].x-points[i].x);//这个double不能除完再转换
                hash[ratio]++;//以斜率为键值进行++；
            }
            map<double,int>::iterator it=hash.begin();
            int local=samePoint+1;//还要加上自己这一点呢
            if(it==hash.end())//这个防止就一个点，或者都在同一个点，那么哈希表就为空了
            {
                if(local>maxPoint)
                    maxPoint=local;
            }
            while(it!=hash.end())//这个就是统计的
            {
                if((local+(it->second))>maxPoint)
                    maxPoint=local+(it->second);
                it++;
            }
        }
        return maxPoint;
        
    }
};