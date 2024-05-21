class Solution {
public:
    int memo(vector<int>& coins, int amount,vector<int>& dp){
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return INT_MAX;
        }
        if(dp[amount]!=-1){
            return dp[amount];
        }
        int ans=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int mincoin=memo(coins,amount-coins[i],dp);
            if(mincoin!=INT_MAX){
                ans=min(ans,1+mincoin);
            }
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        // int ans=memo(coins,amount,dp);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            int ans=INT_MAX;
            for(int j=0;j<coins.size();j++){
                int mincoin=INT_MAX;
                if(i-coins[j]>=0){
                    mincoin=dp[i-coins[j]];
                }
                if(mincoin!=INT_MAX){
                    ans=min(ans,1+mincoin);
                }
            }
            dp[i]=ans;
        }
        if(dp[amount]==INT_MAX){
            return -1;
        }
        return dp[amount];
    }
};