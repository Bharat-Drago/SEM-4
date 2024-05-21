class Solution {
public:
    bool memo(vector<int>& nums,int i,vector<int> &dp){
        if(i==nums.size()-1){
            return true;
        }
        if(nums[i]==0){
            return false;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        for(int j=1;j<=nums[i];j++){
            if(i+j<nums.size()&&memo(nums,i+j,dp)){
               return dp[i]=true;
                
            }
        }
        return dp[i]=false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        // return memo(nums,0,dp);
        dp[n-1]=1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]==0){
                dp[i]=false;
            }
            else if(nums[i]>=n-1-i){
                dp[i]=true;
            }
            else{
                for(int j=1;j<=nums[i];j++){
                     if(i+j<nums.size()&&dp[i+j]){
                        dp[i]=true;
                    }
                }
            }
        }
        return dp[0];
    }
};