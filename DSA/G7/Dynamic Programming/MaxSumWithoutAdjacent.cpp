class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int memo(int i,int* arr,int n,vector<int>& dp){
	    if(i==n-1){
	        return arr[n-1];
	    }
	    if(i>=n){
	        return 0;
	    }
	    if(dp[i]!=-1){
	        return dp[i];
	    }
	    int inc=arr[i]+memo(i+2,arr,n,dp);
	    int n_inc=memo(i+1,arr,n,dp);
	    return dp[i]=max(inc,n_inc);
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int> dp(n,-1);
	   // return memo(0,arr,n,dp);
	   dp[n-1]=arr[n-1];
	   for(int i=n-2;i>=0;i--){
	       int inc=arr[i];
	       if(i<n-2){
	           inc+=dp[i+2];
	       }
	       int n_inc=dp[i+1];
	       dp[i]=max(inc,n_inc);
	   }
	   return dp[0]; 
	}
};