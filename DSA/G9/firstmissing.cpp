#include<iostream>
using namespace std;
int findmissing(int arr[],int n){
	// int temp[n]={0};
	for(int i=0;i<n;i++){
		while(arr[i]>=1&&arr[i]<=n){
			swap(arr[i],arr[arr[i]-1]);
			if(arr[i]==i+1){
				break;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(arr[i]!=i+1){
			return i+1;
		}
	}
	return 0;
}
int main(){
	int n;
	cin>>n;
	int arr[100];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<findmissing(arr,n)<<endl;
	return 0;
}