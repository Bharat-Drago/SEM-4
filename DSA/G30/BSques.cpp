#include<iostream>
using namespace std;
int BS(int arr[],int n,int key){
	int lo=0;
	int hi=n-1;
	int mid;
	while(lo<=hi){
		mid=(lo+hi)/2;
		if(arr[mid]==key){
			return mid;
		}
		else if(arr[mid]>key){
			hi=mid-1;
		}
		else{
			lo=mid+1;
		}
	}
	return -1;
}
pair<int,int> findpair(int arr[],int n,int diff){
	for(int i=0;i<n;i++){
		int x=BS(arr,n,arr[i]+diff);
		if(x!=-1){
			return {i,x};
		}
	}
	return {-1,-1};
}
int minEven(int arr[],int n){
	int lo=0;
	int hi=n-1;
	int mid;
	int ans=-1;
	while(lo<hi){
		mid=(lo+hi)/2;
		if(arr[mid]%2==0){
			ans=mid;
			hi=mid;
		}
		else{
			lo=mid+1;
		}
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
	int diff;
	cin>>diff;
	pair<int,int> p=findpair(arr,n,diff);
	cout<<p.first<<" "<<p.second<<endl;
	return 0;
}