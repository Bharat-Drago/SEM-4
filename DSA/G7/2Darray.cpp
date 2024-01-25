#include<iostream>
using namespace std;

int main(){
	int m,n;
	cin>>m>>n;
	int mat[m][n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>mat[i][j];
		}
	}
	// int flag=0;
	// for(int j=0;j<n;j++){
	// 	if(flag==0){
	// 		for(int i=0;i<m;i++){
	// 			cout<<mat[i][j]<<" ";
	// 		}
	// 		flag=1;
	// 	}
	// 	else{
	// 		for(int i=m-1;i>=0;i--){
	// 			cout<<mat[i][j]<<" ";
	// 		}
	// 		flag=0;
	// 	}
	// }
	int up=0;
	int down=m-1;
	int left=0;
	int right=n-1;
	while(left<=right&&up<=down){
		for(int i=left;i<=right;i++){
			cout<<mat[up][i]<<" ";
		}
		up++;
		for(int i=up;i<=down;i++){
			cout<<mat[i][right]<<" ";
		}
		right--;
		if(down>up){
			for(int i=right;i>=left;i--){
				cout<<mat[down][i]<<" ";
			}
			down--;
		}
		if(left<right){
			for(int i=down;i>=up;i--){
				cout<<mat[i][left]<<" ";
			}
			left++;
		}
	}
	return 0;
}