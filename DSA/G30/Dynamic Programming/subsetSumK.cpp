class Solution{   
public:
    bool memo(vector<int>arr, int sum,int i,vector<vector<int>> &dp){
        if(sum<0||i>=arr.size()){
            return false;
        }
        if(sum==0||(i<=arr.size()-1&&sum==arr[i])){
            return true;
        }
        if(dp[sum][i]!=-1){
            return dp[sum][i];
        }
        bool inc=memo(arr,sum-arr[i],i+1,dp);
        bool n_inc=memo(arr,sum,i+1,dp);
        return dp[sum][i]=inc|n_inc;
        
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>> dp(sum+1,vector<int>(n+1,false));
        // return memo(arr,sum,0,dp);
        for(int i=0;i<=n;i++){
            dp[0][i]=true;
        }
        if(arr[n-1]==sum){
            dp[sum][n-1]=true;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=sum;j++){
                int inc=false;
                if(j-arr[i]>=0){
                    inc=dp[j-arr[i]][i+1];
                }
                int n_inc=dp[j][i+1];
                dp[j][i]=n_inc|inc;
            }
        }
        return dp[sum][0];
    }
};