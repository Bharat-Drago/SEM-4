#include<iostream>
using namespace std;
int count_1bit(int n){
	int count=0;
	while(n){
		if(n&1){
			count++;
		}
		n=n>>1;
	}
	return count;
}
void get_bit(int n,int k){
	if(n&(1<<(k-1))){
		cout<<true<<endl;
	}
	else{
		cout<<false<<endl;
	}
}
int main(){
	int n;
	cin>>n;
	// get_bit(n,k);
	// cout<<(n|(1<<(k-1)))<<endl; //set 1 at Kth bit
	// cout<<(n&(~(1<<(k-1))))<<endl; //set 0 at Kth bit
	cout<<count_1bit(n)<<endl;
	return 0;
}