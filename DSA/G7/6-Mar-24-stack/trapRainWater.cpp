class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=height[0];
        int r=height[n-1];
        vector<int> left(n,0);
        vector<int> right(n,0);
        left[0]=height[0];
        right[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],height[i]);
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            int water=min(left[i],right[i])-height[i];
            if(water>0){
                ans+=water;
            }
        }
        return ans;
    }
};