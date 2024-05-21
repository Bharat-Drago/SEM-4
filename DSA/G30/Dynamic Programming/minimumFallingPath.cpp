class Solution {
public:
    int memo(vector<vector<int>>& matrix,int i,int j,vector<vector<int>> &dp){
        // if(j<0||j>=matrix.size()){
        //     return INT_MAX;
        // }
        if(i==matrix.size()-1){
            return matrix[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int left=INT_MAX;
        int right=INT_MAX;
        
        if(j+1<matrix.size()){
            left=memo(matrix,i+1,j+1,dp);
        }
        if(j-1>=0){
            right=memo(matrix,i+1,j-1,dp);
        }
       int bottom=memo(matrix,i+1,j,dp);
       return dp[i][j]=min(left,min(right,bottom))+matrix[i][j];

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int j=0;j<n;j++){
            // ans=min(ans,memo(matrix,0,j,dp));
            dp[n-1][j]=matrix[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int left=INT_MAX;
                int right=INT_MAX;
                int bottom=INT_MAX;
                if(j+1<n){
                    left=dp[i+1][j+1];
                }
                if(j-1>=0){
                    right=dp[i+1][j-1];
                }
                bottom=dp[i+1][j];
                dp[i][j]=min(left,min(right,bottom))+matrix[i][j];
            }
        }
        for(int i=0;i<n;i++){
            ans=min(ans,dp[0][i]);
        }
        return ans;
    }
};