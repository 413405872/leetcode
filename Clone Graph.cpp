/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==NULL)
        {
            return NULL;
        }
        map<UndirectedGraphNode*,UndirectedGraphNode*> bMap;
        queue<UndirectedGraphNode*> que;
        que.push(node);
        while(!que.empty())
        {
            UndirectedGraphNode* pNode=que.front();//从队列取出一个结点
            que.pop();
            if(!bMap.count(pNode))//如果我hash map里面没有这个结点我就新建,并且插入我的hash-map
            {
                UndirectedGraphNode* newNode=new UndirectedGraphNode(pNode->label);
                bMap[pNode]=newNode;
            }
            for(int i=0;i<pNode->neighbors.size();i++)//遍历刚刚这个结点的每一个邻居结点
            {
                UndirectedGraphNode* ChildNode=pNode->neighbors[i];
                if(!bMap.count(ChildNode))
                {
                    UndirectedGraphNode* newNode=new UndirectedGraphNode(ChildNode->label);
                    bMap[ChildNode]=newNode;
                    que.push(ChildNode);
                }
                bMap[pNode]->neighbors.push_back(bMap[ChildNode]);//让它的所有邻居都放在它的邻居链表中
            }
        }
        return bMap[node];//这个是头结点
        
    }
};