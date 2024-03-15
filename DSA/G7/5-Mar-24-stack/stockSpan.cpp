class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int> ans;
       stack<pair<int,int>> st;
       for(int i=0;i<n;i++){
           int day=1;
           while(!st.empty()&&st.top().first<=price[i]){
               day+=st.top().second;
               st.pop();
           }
           st.push({price[i],day});
           ans.push_back(day);
       }
       return ans;
    }
};