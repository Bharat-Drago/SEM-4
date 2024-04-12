class Solution {
public:
    int row[4]={1,0,-1,0};
    int col[4]={0,1,0,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m=grid.size();
        int n=grid[0].size();
        int count1=0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    vis[i][j]=1;
                }
                else if(grid[i][j]==1){
                    count1++;
                }
            }
        }
        if(count1==0){
          
            return 0;
        }
        int time=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int currow=q.front().first;
                int curcol=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int r=currow+row[k];
                    int c=curcol+col[k];
                    if(r>=0&&r<m&&c>=0&&c<n&&grid[r][c]==1&&vis[r][c]==0){
                        q.push({r,c});
                        vis[r][c]=1;
                    }
                }

            }
            time++;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1&&vis[i][j]==0){
                    return -1;
                }
            }
        }
        return time-1;
    }
};