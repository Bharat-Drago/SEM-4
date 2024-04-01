class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        long long cost=0;
        while(pq.size()>1){
            long long x=pq.top();
            pq.pop();
            long long y=pq.top();
            pq.pop();
            pq.push(x+y);
            cost+=x+y;
        }
        return cost;
    }
};