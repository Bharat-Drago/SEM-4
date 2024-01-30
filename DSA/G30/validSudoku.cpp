#include<iostream>
#include<vector>
using namespace std;
bool valid(vector<vector<char>> mat,int i,int j){
	for(int k=0;k<9;k++){
		if(mat[i][j]==mat[i][k]&&k!=j){
			return false;
		}
		if(mat[i][j]==mat[k][j]&&k!=i){
			return false;
		}
		if(mat[i][j]==mat[3*(i/3)+k/3][3*(j/3)+k%3]&&i!=(3*(i/3)+k/3)&&j!=(3*(j/3)+k%3)){
			return false;
		}
	}
	return true;
}
bool validSudoku(vector<vector<char>> mat){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(mat[i][j]!='.'&&!valid(mat,i,j)){
				return false;
			}
		}
	}
	return true;
}
int main(){
	vector<vector<char>> mat(9,vector<char>(9));
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cin>>mat[i][j];
		}
	}
	if(validSudoku(mat)){
		cout<<"valid sudoku"<<endl;
	}
	else{
		cout<<"invalid sudoku"<<endl;
	}
	return 0;
}