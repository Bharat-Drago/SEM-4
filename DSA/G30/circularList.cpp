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
void deleteNode(ListNode* &head,int idx){
	ListNode* temp=head;
	if(idx==0){
		while(temp->next!=head){
			temp=temp->next;
		}
		head=head->next;
		temp->next=head;
		return;
	}
	while(idx>1){
		temp=temp->next;
		idx--;
	}
	temp->next=temp->next->next;
}
void insertAtHead(ListNode* &head,int x){
	ListNode* node=new ListNode(x);
	ListNode* temp=head;
	while(temp->next!=head){
		temp=temp->next;
	}
	node->next=head;
	temp->next=node;
	head=node;
}
void insertAtEnd(ListNode* &head,int x){
	if(head==NULL){
		head=new ListNode(x);
		head->next=head;
		return;
	}
	ListNode* temp=head;
	while(temp->next!=head){
		temp=temp->next;
	}
	ListNode* node=new ListNode(x);
	temp->next=node;
	node->next=head;
}
void display(ListNode* head){
	ListNode* temp=head;
	while(temp->next!=head){
		cout<<temp->val<<" ";
		temp=temp->next;
	}
	cout<<temp->val<<" "<<temp->next->val<<endl;
}
int main(){
	ListNode* head=NULL;
	int n;
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		insertAtEnd(head,x);
	}
	insertAtHead(head,5);
	deleteNode(head,0);
	display(head);
	return 0;
}