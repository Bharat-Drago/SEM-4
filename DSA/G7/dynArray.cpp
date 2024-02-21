#include<iostream>
using namespace std;

int main(){
	int* x=new int[3*4];
	for(int i=0;i<4;i++){
		// x[i]=new int[3];
		for(int j=0;j<3;j++){
			cin>>x[i*4+j];
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			cout<<x[4*i+j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}