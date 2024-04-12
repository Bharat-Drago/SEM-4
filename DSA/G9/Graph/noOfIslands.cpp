class Solution {
public:
    int row[4]={1,0,-1,0};
    int col[4]={0,1,0,-1};
    void dfs(vector<vector<char>>& grid,vector<vector<int>> &vis,int i,int j){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]=='0'||vis[i][j]==1){
            return;
        }
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int r=i+row[k];
            int c=j+col[k];
            dfs(grid,vis,r,c);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0&&grid[i][j]=='1'){
                    dfs(grid,vis,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};