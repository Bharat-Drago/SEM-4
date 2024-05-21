class Solution {
  public:
    int fibo(int n,vector<int> &dp){
        if(n==0||n==1){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans=(fibo(n-1,dp)+fibo(n-2,dp))%(1000000007);
        return dp[n]=ans;
    }
    int nthFibonacci(int n){
        // code here
        if(n==0){
            return 0;
        }
        vector<int> dp(n+1,-1);
        // return fibo(n,dp);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=(dp[i-1]+dp[i-2])%1000000007;
        }
        return dp[n];
    }
};