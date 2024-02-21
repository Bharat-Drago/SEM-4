#include<iostream>
using namespace std;
class solution{
	int arr[10];
public:
	solution(int *arr){
		for(int i=0;i<10;i++){
			this->arr[i]=arr[i];
		}
	}
	void display(){
		for(int i=0;i<10;i++){
			cout<<arr[i]<<" ";
		}
	}
};
int main(){
	int arr[10];
	for(int i=0;i<10;i++){
		cin>>arr[i];
	}
	solution* s=new solution(arr);
	s->display();
	return 0;
}