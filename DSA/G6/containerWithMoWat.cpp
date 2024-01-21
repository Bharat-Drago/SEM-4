#include<iostream>
using namespace std;
int mostWater(int arr[],int n){
	int ans=0;
	int i=0;
	int j=n-1;
	while(i<j){
		int area=(j-i)*min(arr[i],arr[j]);
		ans=max(ans,area);
		if(arr[i]>arr[j]){
			j--;
		}
		else{
			i++;
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
	cout<<mostWater(arr,n)<<endl;;
	return 0;
}