class Solution {
public:
    bool bfs(vector<vector<int>>& graph,vector<int> &vis,int i){
        queue<pair<int,int>> q;
        q.push({i,0});
        vis[i]=0;
        while(!q.empty()){
            int node=q.front().first;
            int color=q.front().second;
            q.pop();
            for(int x:graph[node]){
                if(vis[x]==-1){
                    if(color==0){
                        q.push({x,1});
                        vis[x]=1;
                    }
                    else{
                        q.push({x,0});
                        vis[x]=0;
                    }
                }
                else if(vis[x]==color){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(!bfs(graph,vis,i)){
                    return false;
                }
            }
        }
        return true;
    }
};