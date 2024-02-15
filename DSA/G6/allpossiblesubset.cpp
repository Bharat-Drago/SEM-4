#include<iostream>
using namespace std;
void helper(string str,string osf,int idx){
	if(idx==str.size()){
		cout<<osf<<endl;
		return;
	}
	helper(str,osf,idx+1);
	helper(str,osf+str[idx],idx+1);
}
int main(){
	string str;
	cin>>str;
	string osf="";
	helper(str,osf,0);
	return 0;
}