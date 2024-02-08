#include<bits/stdc++.h>
using namespace std;
void helper(int i,int j,int m,int n,string osf){
	if(i==m-1&&j==n-1){
		cout<<osf<<endl;
		return;
	}
	if(i>=m||j>=n){
		return;
	}
	helper(i,j+1,m,n,osf+'R');
	helper(i+1,j,m,n,osf+'D');
}
int main(){
	int m,n;
	cin>>m>>n;
	string osf="";
	helper(0,0,m,n,osf);
	return 0;
}