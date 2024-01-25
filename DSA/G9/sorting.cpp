#include<iostream>
#include<algorithm>
using namespace std;
void insertion(int *arr,int n){
	for(int i=1;i<n;i++){
		int current=arr[i];
		int j=i-1;
		while(j>=0&&arr[j]>current){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=current;
	}
}
void selection(int *arr,int n){
	for(int i=0;i<n;i++){
		int small=i;
		for(int j=i+1;j<n;j++){
			if(arr[small]>arr[j]){
				small=j;
			}
		}
		swap(arr[i],arr[small]);
	}
}
void bubble(int *arr,int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
		}
	}
}
int main(){
	int n;
	cin>>n;
	int arr[100];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	// bubble(arr,n);
	// selection(arr,n);
	// insertion(arr,n);
	sort(arr,arr+10);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}