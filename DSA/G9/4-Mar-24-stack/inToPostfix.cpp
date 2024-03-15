#include<bits/stdc++.h>
using namespace std;
int prec(char ch){
	if(ch=='^'){
		return 3;
	}
	else if(ch=='*'||ch=='/'){
		return 2;
	}
	else if(ch=='+'||ch=='-'){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	string str;
	cin>>str;
	//str=a+b*(c-d)/e
	string ans="";
	stack<char> s;
	for(int i=0;i<str.size();i++){
		if(str[i]>='a'&&str[i]<='z'){
			ans+=str[i];
		}
		else if(str[i]=='('){
			s.push(str[i]);
		}
		else if(str[i]==')'){
			while(s.top()!='('){
				ans+=s.top();
				s.pop();
			}
			s.pop();
		}
		else{
			while(!s.empty()&&prec(s.top())>=prec(str[i])){
				ans+=s.top();
				s.pop();
			}
			s.push(str[i]);
		}
	}
	while(!s.empty()){
		ans+=s.top();
		s.pop();
	}
	cout<<ans<<endl;
	return 0;
}