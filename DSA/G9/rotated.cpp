#include<iostream>
using namespace std;
int minElement(int arr[],int n){
	int lo=0;
	int hi=n-1;
	int mid;
	while(lo<hi){
		mid=(lo+hi)/2;
		if(arr[mid]>arr[hi]){
			lo=mid+1;
		}
		else if(arr[mid]<arr[hi]){
			hi=mid;
		}
	}
	return lo;
}
int binaryInRotated(int arr[],int key,int n){
	int pivot=minElement(arr,n);
	int lo=0;
	int hi=n-1;
	int mid;
	while(lo<=hi){
		mid=(lo+hi)/2;
		int rm=(mid+pivot)%10;
		if(arr[rm]==key){
			return rm;
		}
		else if(arr[rm]>key){
			hi=mid-1;
		}
		else{
			lo=mid+1;
		}
	}
	return -1;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int key;
	cin>>key;
	cout<<binaryInRotated(arr,key,n)<<endl;
	return 0;
}