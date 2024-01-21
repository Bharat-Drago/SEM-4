#include<iostream>
using namespace std;
pair<int,int> subarray(int arr[],int n,int k,int target){
	int sum=0;
	for(int i=0;i<k;i++){
		sum+=arr[i];
	}
	int i=0;
	int j=k-1;
	while(j<n){
		if(sum==target){
			return {i,j};
		}
		sum=sum-arr[i]+arr[j+1];
		i++;
		j++;
	}
	return {-1,-1};
}
int main(){
	int n;
	cin>>n;
	int arr[100];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int k,target;
	cin>>k>>target;
	pair<int,int> p=subarray(arr,n,k,target);
	cout<<p.first<<" "<<p.second<<endl;
	return 0;
}