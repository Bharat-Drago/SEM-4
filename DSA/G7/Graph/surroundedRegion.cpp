class Solution {
public:
int row[4]={1,0,-1,0};
int col[4]={0,1,0,-1};
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> q;
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            if(board[0][i]=='O'&&!vis[0][i]){
                q.push({0,i});
                vis[0][i]=1;
            }
            if(board[m-1][i]=='O'&&!vis[m-1][i]){
                q.push({m-1,i});
                vis[m-1][i]=1;
            }
        }
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'&&!vis[i][0]){
                q.push({i,0});
                vis[i][0]=1;
            }
            if(board[i][n-1]=='O'&&!vis[i][n-1]){
                q.push({i,n-1});
                vis[i][n-1]=1;
            }
        }
        while(!q.empty()){
            int curcol=q.front().second;
            int currow=q.front().first;
            q.pop();
            for(int i=0;i<4;i++){
                int r=currow+row[i];
                int c=curcol+col[i];
                if(r>=0&&r<m&&c>=0&&c<n&&!vis[r][c]&&board[r][c]=='O'){
                    q.push({r,c});
                    vis[r][c]=1;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]&&board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};