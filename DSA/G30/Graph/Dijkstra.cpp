class Solution
{
    public:
    //Function to find the shortest distance of all the vertices
    //from the source vertex S.
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dis(V,1e9);
        dis[S]=0;
        pq.push({0,S});
        while(!pq.empty()){
            int curdis=pq.top().first;
            int curnode=pq.top().second;
            pq.pop();
            for(auto x:adj[curnode]){
                int child=x[0];
                int wt=x[1];
                if(curdis+wt<dis[child]){
                    dis[child]=curdis+wt;
                    pq.push({dis[child],child});
                }
            }
        }
        return dis;
    }
};