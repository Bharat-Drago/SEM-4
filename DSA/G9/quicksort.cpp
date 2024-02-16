#include<bits/stdc++.h>
using namespace std;
int partition(vector<int> &vec,int l,int r){
	int pivot=vec[r];
	int i=l-1;
	for(int j=l;j<=r;j++){
		if(vec[j]<pivot){
			i++;
			swap(vec[i],vec[j]);
		}
	}
	swap(vec[i+1],vec[r]);
	return i+1;
}
void quicksort(vector<int> &vec,int l,int r){
	if(l<r){
		int pidx=partition(vec,l,r);
		quicksort(vec,l,pidx-1);
		quicksort(vec,pidx+1,r);
	}
}
int main(){
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++){
		cin>>vec[i];
	}
	quicksort(vec,0,n-1);
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<" ";
	}
	return 0;
}