//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int> adj[],vector<int> &vis,vector<int> &path,int i){
        vis[i]=1;
        path[i]=1;
        for(int x:adj[i]){
            if(!vis[x]){
                if(dfs(adj,vis,path,x)){
                    return true;
                }
            }
            else if(path[x]==1){
                return true;
            }
        }
        path[i]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        // vector<int> vis(V,0);
        // vector<int> path(V,0);
        // for(int i=0;i<V;i++){
        //     if(!vis[i]){
        //         if(dfs(adj,vis,path,i)){
        //             return true;
        //         }
        //     }
        // }
        // return false;
        vector<int> ans;
        vector<int> indeg(V,0);
       for(int i=0;i<V;i++){
           for(int x:adj[i]){
               indeg[x]++;
           }
       }
       queue<int> q;
       for(int i=0;i<V;i++){
           if(indeg[i]==0){
               q.push(i);
           }
       }
       while(!q.empty()){
           int node=q.front();
           q.pop();
           ans.push_back(node);
           for(int x:adj[node]){
               indeg[x]--;
               if(indeg[x]==0){
                   q.push(x);
               }
           }
       }
       return ans.size()<V;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
