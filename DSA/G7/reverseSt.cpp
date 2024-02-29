#include<bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int> &s,int ele){
	if(s.size()==0){
		s.push(ele);
		return;
	}
	int data=s.top();
	s.pop();
	insertAtBottom(s,ele);
	s.push(data);
}
void reverse(stack<int> &s){
	if(s.size()==0){
		return;
	}
	int ele=s.top();
	s.pop();
	reverse(s);
	insertAtBottom(s,ele);
}
void display(stack<int> s){
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
}
int main(){
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	display(s);
	reverse(s);
	display(s);
	return 0;
}
