class Solution {
  public:
    void dfs(vector<pair<int,int>> graph[],vector<int> &vis,stack<int> &st,int i){
        vis[i]=1;
        for(auto x:graph[i]){
            if(!vis[x.first]){
                dfs(graph,vis,st,x.first);
            }
        }
        st.push(i);
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> graph[N];
        for(int i=0;i<M;i++){
            int v1=edges[i][0];
            int v2=edges[i][1];
            int wt=edges[i][2];
            graph[v1].push_back({v2,wt});
        }
        stack<int> st;
        vector<int> vis(N,0);
        for(int i=0;i<N;i++){
            if(!vis[i]){
                dfs(graph,vis,st,i);
            }
        }
        vector<int> dis(N,1e9);
        dis[0]=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            for(auto x:graph[node]){
                int child=x.first;
                int wt=x.second;
                if(dis[node]+wt<dis[child]){
                    dis[child]=dis[node]+wt;
                }
            }
        }
        for(int i=0;i<N;i++){
            if(dis[i]==1e9){
                dis[i]=-1;
            }
        }
        return dis;
    }
};