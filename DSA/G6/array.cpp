#include<iostream>
using namespace std;
void reverse(int arr[],int n){
	
}
void deletion(int arr[],int pos ,int &n){
	for(int i=pos;i<n;i++){
		arr[i]=arr[i+1];
	}
	n--;
}
void insertion(int arr[],int &n,int key,int pos){
	for(int i=n;i>=pos;i--){
		arr[i]=arr[i-1];
	}
	arr[pos]=key;
	n++;
}
int main(){
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	int n=sizeof(arr)/sizeof(arr[0]);
	//key=12,pos=4
	int key=12;
	int pos=4;
	// insertion(arr,n,key,pos);
	deletion(arr,pos,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}