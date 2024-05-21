class Solution {
public:

int helper(int i,int j,int m,int n,vector<vector<int>> &dp){
    if(i>=m||j>=n){
        return 0;
    }
    if(i==m-1&&j==n-1){
        return 1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int right=helper(i,j+1,m,n,dp);
    int down=helper(i+1,j,m,n,dp);
    return dp[i][j]=right+down;
}
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        // return helper(0,0,m,n,dp);
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1&&j==n-1){
                    dp[i][j]=1;
                }
                else{
                    int d=0;
                    int r=0;
                    if(i+1<m){
                        d=dp[i+1][j];
                    }
                    if(j+1<n){
                        r=dp[i][j+1];
                    }
                    dp[i][j]=d+r;
                }
            }
        }
        return dp[0][0];
    }
};