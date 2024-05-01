class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<pair<int,int>> graph[n];
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<int> dis(n,1e9);
        dis[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<int> parent(n+1);
        
        while(!pq.empty()){
            int curdis=pq.top().first;
            int curnode=pq.top().second;
            pq.pop();
            if(curdis>dis[curnode]){
                continue;
            }
            for(auto x:graph[curnode]){
                int child=x.first;
                int wt=x.second;
                if(curdis+wt<disappear[child]&&curdis+wt<dis[child]){
                    dis[child]=curdis+wt;
                    pq.push({dis[child],child});
                    
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dis[i]==1e9){
                dis[i]=-1;
            }
        }
        return dis;
    }
};