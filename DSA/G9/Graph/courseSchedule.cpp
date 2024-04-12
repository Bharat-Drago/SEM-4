class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> graph[numCourses];
        for(int i=0;i< prerequisites.size();i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> indeg(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(int x:graph[i]){
                indeg[x]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(int x:graph[node]){
                indeg[x]--;
                if(indeg[x]==0){
                    q.push(x);
                }
            }
        }
        return numCourses==count;
    }
};