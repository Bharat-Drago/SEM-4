#include<iostream>
using namespace std;
class ListNode{
public:
	int val;
	ListNode* next;
	ListNode* prev;
	ListNode(int x){
		val=x;
		next=NULL;
		prev=NULL;
	}
	ListNode(int x,ListNode* n,ListNode* p){
		val=x;
		next=n;
		prev=p;
	}
};
void insertAthead(ListNode* &head,int data){
	ListNode* node=new ListNode(data);
	node->next=head;
	head->prev=node;
	head=node;
}
void insertAtMid(ListNode* head,int idx,int data){
	ListNode* temp=head;
	while(idx>1){
		temp=temp->next;
		idx--;
	}
	ListNode* forw=temp->next;
	ListNode* node=new ListNode(data);
	temp->next=node;
	node->next=forw;
	forw->prev=node;
	node->prev=temp;
}
void insertAtend(ListNode* &tail,int data){
	tail->next=new ListNode(data);
	tail->next->prev=tail;
	tail=tail->next;
}
void displayh(ListNode* head){
	ListNode* temp=head;
	while(temp){
		cout<<temp->val<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
void displayt(ListNode* tail){
	ListNode* temp=tail;
	while(temp){
		cout<<temp->val<<" ";
		temp=temp->prev;
	}
	cout<<endl;
}
int main(){
	ListNode* head=new ListNode(0);
	ListNode* tail=head;
	int n;
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		insertAtend(tail,x);
	}
	insertAthead(head,5);
	insertAtMid(head,2,10);
	displayh(head);
	displayt(tail);
	return 0;
}