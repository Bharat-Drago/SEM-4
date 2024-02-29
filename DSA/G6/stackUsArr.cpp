#include<iostream>
using namespace std;
class Stack{
	int* arr;
	int capacity;
	int top;
public:
	Stack(int cap){
		capacity=cap;
		top=-1;
		arr=new int[cap];
	}
	void push(int x){
		if(top==capacity-1){
			cout<<"stack overflow"<<endl;
			return;
		}
		top++;
		arr[top]=x;
	}
	void pop(){
		if(top==-1){
			cout<<"stack underflow"<<endl;
			return;
		}
		top--;
	}
	int peak(){
		if(top==-1){
			cout<<"there is no element in the stack"<<endl;
			return -1;
		}
		return arr[top];
	}
	bool isEmpty(){
		return top==-1;
	}
	int size(){
		return top+1;
	}
};
void display(Stack s){
	while(!s.isEmpty()){
		cout<<s.peak()<<" ";
		s.pop();
	}
	cout<<endl;
}
int main(){
	Stack s(4);
	s.pop();
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.pop();
	s.push(5);
	display(s);
	return 0;
}