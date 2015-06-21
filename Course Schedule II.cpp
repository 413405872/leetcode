class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<int> back;//要返回的
        vector<set<int> > req(numCourses);
        vector<int> indegree(numCourses);
        queue<int> zero;
        for(int i=0;i<prerequisites.size();i++)//构建邻接表
        {
            req[prerequisites[i].second].insert(prerequisites[i].first);
        }
        for(int i=0;i<numCourses;i++)//有几个前提条件，度就是几。
        {
            for(auto it=req[i].begin();it!=req[i].end();it++)
            {
                (indegree[*it])++;
            }
        }
        for(int i=0;i<numCourses;i++)//度为0的就没有前提条件，可以直接完成
        {
            if(indegree[i]==0)
            {
                zero.push(i);
            }
        }
        while(!zero.empty())//广度遍历
        {
            int temp=zero.front();
            back.push_back(temp);
            zero.pop();
            for(auto it=req[temp].begin();it!=req[temp].end();it++)
            {
                if(--(indegree[*it])==0)
                {
                    zero.push(*it);
                }
            }
            --numCourses;
        }
        if(numCourses==0)
        {
            return back;
        }
        else
        {
            back.clear();
            return back;
        }
        
        
    }
};