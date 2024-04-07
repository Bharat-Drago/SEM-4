#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> graph[],unordered_map<int,bool> &vis,int i){
	vis[i]=true;

	for(int x:graph[i]){
		
		if(!vis[x]){
			cout<<"parent : "<<i<<"child : "<<x<<endl;
			dfs(graph,vis,x);
		}
	}
}
void bfs(vector<int> graph[],unordered_map<int,bool> &vis,int i){
	queue<int> q;
	q.push(i);
	vis[i]=true;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int j:graph[x]){
			if(!vis[j]){
				q.push(j);
				cout<<"parent : "<<x<<"child : "<<j<<endl;
				vis[j]=true;
			}
		}
	}
}
int main(){
	int v,e;
	cin>>v>>e;
	unordered_map<int,bool> vis;
	vector<int> graph[v];
	for(int i=0;i<e;i++){
		int v1,v2;
		cin>>v1>>v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
		
	}
	for(int i=0;i<v;i++){
		if(!vis[i]){
			bfs(graph,vis,i);
		}
	}
	return 0;
}