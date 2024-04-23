class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> graph[N];
        for(int i=0;i<M;i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> dis(N,INT_MAX-1);
        queue<int> q;
        q.push(src);
        dis[src]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int x:graph[node]){
                if(dis[x]>dis[node]+1){
                    dis[x]=dis[node]+1;
                    q.push(x);
                }
            }
        }
        for(int i=0;i<N;i++){
            if(dis[i]==INT_MAX-1){
                dis[i]=-1;
            }
        }
        return dis;
    }
};