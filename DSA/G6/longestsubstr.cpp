#include<iostream>
using namespace std;
int substring(string str){
	int ans=0;
	int n=str.size();
	int freq[128]={0};
	int i=0;
	int j=0;
	while(j<n){
		if(freq[str[j]-'\0']+1>1){
			freq[str[i]-'\0']--;
			i++;
		}
		else{
			freq[str[j]-'\0']++;
			ans=max(ans,j-i+1);
			j++;
		}
	}
	return ans;
}
int main(){
	string str;
	cin>>str;
	cout<<substring(str)<<endl;
	return 0;
}
