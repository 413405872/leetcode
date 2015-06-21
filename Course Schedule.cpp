class Solution {
public:
   bool canFinish(int numCourses, vector<pair<int, int> > &prerequisites) {
       vector<set<int> > req(numCourses);//这个就是一个邻接表
       vector<int> indegree(numCourses);//入度
       queue<int> zero;
       for(int i=0;i<prerequisites.size();i++)
       {
           req[prerequisites[i].second].insert(prerequisites[i].first);//need[second]里是一个链表，放的是它能满足谁如0里放1,2,3那就意味着，0完成了才能做1,2,3，也许1,2,3还有其他前置条件
       }
       for(int i=0;i<numCourses;i++)
       {
           for(auto iter=req[i].begin();iter!=req[i].end();iter++)
           {
               (indegree[*iter])++;//这个就是看你有几个前驱，有一个加一个
           }
       }
       for(int i=0;i<numCourses;i++)
       {
           if(indegree[i]==0)
           {
               zero.push(i);//就是入度为0的，也就是没有前驱的那我入队列呗
           }
       }
       while(!zero.empty())
       {
           int seq=zero.front();
           zero.pop();
           for(auto iter=req[seq].begin();iter!=req[seq].end();iter++)
           {
               if(--indegree[*iter]==0)
               {
                   zero.push(*iter);//每次都在减一个入度，如果减到0了这门课程就可以完成了
               }
           }
           --numCourses;
       }
       return numCourses==0;
    }
};