#include<iostream>
using namespace std;
class ListNode{
public:
	int val;
	ListNode* next;
	ListNode(int x){
		val=x;
		next=NULL;
	}
};
class Stack{
	ListNode* top;
	int capacity;
	int csize;
public:
	Stack(int cap){
		capacity=cap;
		top=NULL;
		csize=0;
	}
	void push(int x){
		if(csize==capacity){
			cout<<"stack overflow"<<endl;
			return;
		}
		if(csize==0){
			top=new ListNode(x);
			csize++;
			return;
		}
		ListNode* node=new ListNode(x);
		node->next=top;
		top=node;
		csize++;
	}
	void pop(){
		if(csize==0){
			cout<<"stack underflow"<<endl;
			return;
		}
		ListNode* temp=top;
		top=top->next;
		delete temp;
		csize--;
	}
	int peak(){
		if(csize==0){
			cout<<"there is no element in the stack"<<endl;
			return -1;
		}
		return top->val;
	}
	bool isEmpty(){
		return csize==0;
	}
	int size(){
		return csize;
	}
};
void copystack(Stack s1,Stack &s2){
	if(s1.size()==0){
		return;
	}
	int data=s1.peak();
	s1.pop();
	copystack(s1,s2);
	s2.push(data);
}
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
	Stack s2(4);
	copystack(s,s2);
	cout<<s.peak()<<endl;
	// display(s);
	display(s2);
	// cout<<s.peak()<<endl;
	return 0;
}