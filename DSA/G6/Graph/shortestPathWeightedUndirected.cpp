class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>> graph[n+1];
        for(int i=0;i<m;i++){
            graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<int> dis(n+1,1e9);
        dis[1]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,1});
        vector<int> parent(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        while(!pq.empty()){
            int curdis=pq.top().first;
            int curnode=pq.top().second;
            pq.pop();
            for(auto x:graph[curnode]){
                int child=x.first;
                int wt=x.second;
                if(curdis+wt<dis[child]){
                    dis[child]=curdis+wt;
                    pq.push({dis[child],child});
                    parent[child]=curnode;
                }
            }
        }
        if(dis[n]==1e9){
            return {-1};
        }
        vector<int> ans;
        int i=n;
        while(i!=parent[i]){
            ans.push_back(i);
            i=parent[i];
        }
        ans.push_back(1);
        ans.push_back(dis[n]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};