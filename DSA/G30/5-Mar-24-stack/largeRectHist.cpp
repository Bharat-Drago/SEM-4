class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st;
        vector<int> pse;
        vector<int> nse;
        int n=heights.size();
        for(int i=0;i<n;i++){
            while(!st.empty()&&st.top().first>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                pse.push_back(-1);
            }
            else{
                pse.push_back(st.top().second);
            }
            st.push({heights[i],i});
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&st.top().first>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                nse.push_back(n);
            }
            else{
                nse.push_back(st.top().second);
            }
            st.push({heights[i],i});
        }
        reverse(nse.begin(),nse.end());
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,(nse[i]-pse[i]-1)*heights[i]);
        }
        return ans;
    }
};