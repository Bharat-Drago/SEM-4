#include<iostream>
using namespace std;
int maxSubarray(int arr[],int n,int k){
	int ans=0;
	int sum=0;
	int i=0;
	int j=0;
	while(j<n){
		sum+=arr[j];
		while(sum>k){
			sum-=arr[i];
			i++;
		}
		if(sum==k){
			ans=max(ans,j-i+1);
		}
		j++;
	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	int arr[100];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int k;
	cin>>k;
	cout<<maxSubarray(arr,n,k);
	return 0;
}