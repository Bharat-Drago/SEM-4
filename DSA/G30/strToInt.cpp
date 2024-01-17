#include<iostream>
using namespace std;
long long strToInt(string str){
	long long ans=0;
	int i=0;
	while(i<str.size()){
		ans*=10;
		ans+=str[i]-'0';
		i++;
	}
	return ans;
}
int main(){
	string str;
	cin>>str;
	cout<<strToInt(str)<<endl;
	return 0;
}
