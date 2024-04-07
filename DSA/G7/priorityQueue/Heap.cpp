#include<iostream>
using namespace std;
class heap{
	int *arr;
	int size;
	int capacity;
public:
	heap(int c){
		capacity=c;
		arr=new int[c];
		size=0;
	}
	void push(int x){
		if(size==capacity){
			cout<<"heap overflow"<<endl;
			return;
		}
		arr[size]=x;
		int i=size;
		size++;
		while(i>0){
			if(arr[i]>arr[(i-1)/2]){
				swap(arr[i],arr[(i-1)/2]);
			}
			i=(i-1)/2;
		}
	}
	void pop(){
		if(size==0){
			cout<<" heap underflow"<<endl;
			return ;
		}
		arr[0]=arr[size-1];
		size--;
		int i=0;
		while(i<size){
			int left=2*i+1;
			int right=2*i+2;
			if(left<size&&arr[left]>arr[i]&&arr[left]>arr[right]){
				swap(arr[i],arr[left]);
				i=left;
			}
			else if(right<size&&arr[right]>arr[i]&&arr[right]>arr[left]){
				swap(arr[i],arr[right]);
				i=right;
			}
			else{
				break;
			}
		}
	}
	int top(){
		return arr[0];
	}
	int heapsize(){
		return size;
	}
	bool empty(){
		return size==0;
	}
};
void heapify(int *arr,int size,int i){
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<size&&arr[largest]<arr[left]){
		largest=left;
	}
	if(right<size&&arr[right]>arr[largest]){
		largest=right;
	}
	if(largest!=i){
		swap(arr[i],arr[largest]);
		heapify(arr,size,largest);
	}
}

int main(){
	heap h(5);
	h.push(10);
	cout<<h.top()<<endl;
	h.push(20);
	cout<<h.top()<<endl;
	h.push(7);
	cout<<h.top()<<endl;
	h.push(25);
	cout<<h.top()<<endl;
	h.pop();
	cout<<h.top()<<endl;
	h.pop();
	cout<<h.top()<<endl;
	h.pop();
	cout<<h.top()<<endl;
	cout<<h.heapsize()<<endl;
	cout<<h.empty()<<endl;
	int arr[]={1,2,10,4,5,8,6,7,3};
	int n=9;
	for(int i=(n/2)-1;i>=0;i--){
		heapify(arr,n,i);
	}
	
	for(int i=0;i<9;i++){
		cout<<arr[i]<<" ";
	}
}