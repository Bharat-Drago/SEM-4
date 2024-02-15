//only class solution
// Rat in a maze problem 1-GFG
class Solution{
    public:
    int row[4]={0,1,0,-1};
    int col[4]={1,0,-1,0};
    string str="RDLU";
    void helper(vector<string> &ans,string osf,vector<vector<bool>> &vis,int i,int j,vector<vector<int>> &m,int n){
        if(i>=n||j>=n||i<0||j<0||m[i][j]==0||vis[i][j]==true){
            return;
        }
        if(i==n-1&&j==n-1){
            ans.push_back(osf);
            return;
        }
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            helper(ans,osf+str[k],vis,i+row[k],j+col[k],m,n);
        }
        vis[i][j]=false;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string osf="";
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        helper(ans,osf,vis,0,0,m,n);
        return ans;
    }
};