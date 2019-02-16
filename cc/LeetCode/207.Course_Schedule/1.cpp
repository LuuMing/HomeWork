class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        int indegree[numCourses] = {0};
        int cnt = 0;
        queue<int> q;
        for( auto & pair: prerequisites )
        {
            adj[pair.second].push_back(pair.first);
            indegree[pair.first]++;
        }
        for(int i = 0; i < numCourses;i++)
        {
            if( indegree[i] == 0)
            {
                q.push(i);
            }   
        }
        while( !q.empty() )
        {
            int front = q.front();
            for(auto & node :adj[front])
            {
                if(--indegree[node]==0)
                    q.push(node);
            }
            cnt++;
            q.pop();
        }
        return cnt == numCourses;
    }
};
