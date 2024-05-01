#define p pair<int,pair<int,int>>
class Solution {
public:
    int row[8]={1,0,-1,0,1,1,-1,-1};
    int col[8]={0,1,0,-1,1,-1,1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1){
            return -1;
        }
        int n=grid.size();
        vector<vector<int>> dis(n,vector<int>(n,1e9));
        dis[0][0]=1;
        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({1,{0,0}});
        while(!pq.empty()){
            int curdis=pq.top().first;
            int currow=pq.top().second.first;
            int curcol=pq.top().second.second;
            pq.pop();
            if(currow==n-1&&curcol==n-1){
                return dis[currow][curcol];
            }
            for(int i=0;i<8;i++){
                int r=currow+row[i];
                int c=curcol+col[i];
                if(r>=0&&r<n&&c>=0&&c<n&&grid[r][c]==0&&curdis+1<dis[r][c]){
                    dis[r][c]=1+curdis;
                    pq.push({dis[r][c],{r,c}});
                }
            }
        }
        return -1;
    }
};