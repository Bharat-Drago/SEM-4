class Solution {
public:
    void dfs(vector<vector<int>>& grid,unordered_map<int,bool> &vis,int i){
        vis[i]=true;
        for(int j=0;j<grid.size();j++){
            if(i!=j&&!vis[j]&&grid[i][j]==1){
                dfs(grid,vis,j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,bool> vis;
        int count=0;
        for(int i=0;i<isConnected.size();i++){
            if(!vis[i]){
                count++;
                dfs(isConnected,vis,i);
            }
        }
        return count;
    }
};