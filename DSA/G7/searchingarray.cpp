#include<iostream>
using namespace std;
pair<int,int> binaryFL(int arr[],int key,int n){
	int first=-1;
	int last=-1;
	int lo=0;
	int hi=n-1;
	int mid;
	while(lo<=hi){
		mid=lo+(hi-lo)/2;
		if(arr[mid]==key){
			first=mid;
			hi=mid-1;
		}
		else if(arr[mid]>key){
			hi=mid-1;
		}
		else{
			lo=mid+1;
		}
	}
	lo=0;
	hi=n-1;
	while(lo<=hi){
		mid=lo+(hi-lo)/2;
		if(arr[mid]==key){
			last=mid;
			lo=mid+1;
		}
		else if(arr[mid]>key){
			hi=mid-1;
		}
		else{
			lo=mid+1;
		}
	}
	return {first,last};
}
pair<int,int> fisrtlast(int arr[],int key,int n){
	int first=-1;
	int last=-1;
	for(int i=0;i<n;i++){
		if(arr[i]==key){
			if(first==-1){
				first=i;
				last=i;
			}
			else{
				last=i;
			}
		}
	}
	return {first,last};
}
int binary(int arr[],int key,int n){
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
int linear(int arr[],int key,int n){
	for(int i=0;i<n;i++){
		if(arr[i]==key){
			return i;
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
	// cout<<linear(arr,key,n)<<endl;
	// cout<<binary(arr,key,n)<<endl;
	// pair<int,int> p=fisrtlast(arr,key,n);
	pair<int,int> p=binaryFL(arr,key,n);
	cout<<p.first<<" "<<p.second<<endl;
	return 0;
}