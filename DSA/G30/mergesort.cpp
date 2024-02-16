#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int> &vec,int l,int mid,int r){
	int n1=mid-l+1;
	int n2=r-mid;
	int arr1[n1];
	int arr2[n2];
	for(int i=0;i<n1;i++){
		arr1[i]=vec[l+i];
	}
	for(int i=0;i<n2;i++){
		arr2[i]=vec[mid+1+i];
	}
	int i=0;
	int j=0;
	int k=l;
	while(i<n1&&j<n2){
		if(arr1[i]<arr2[j]){
			vec[k]=arr1[i];
			i++;
		}
		else{
			vec[k]=arr2[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		vec[k]=arr1[i];
		i++;
		k++;
	}
	while(j<n2){
		vec[k]=arr2[j];
		j++;
		k++;
	}
}
void mergesort(vector<int> &vec,int l,int r){
	if(l>=r){
		return ;
	}
	int mid=l+(r-l)/2;
	mergesort(vec,l,mid);
	mergesort(vec,mid+1,r);
	merge(vec,l,mid,r);
}
int main(){
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++){
		cin>>vec[i];
	}
	mergesort(vec,0,n-1);
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<" ";
	}
	return 0;
}