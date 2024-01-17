#include<iostream>
using namespace std;
void sort(char *arr,int n){
	int freq[26]={0};
	for(int i=0;i<n;i++){
		freq[arr[i]-'a']++;
	}
	int j=0;
	for(int i=0;i<26;i++){
		while(freq[i]!=0){
			arr[j]=(char)(i+'a');
			j++;
			freq[i]--;
		}
	}
}
void insertion(char* arr,int &n,char key,int pos){
	for(int i=n+1;i>pos;i--){
		arr[i]=arr[i-1];
	}
	n++;
	arr[pos]=key;
}
void deletion(char* arr,int &n,int pos){
	for(int i=pos;i<n;i++){
		arr[i]=arr[i+1];
	}
	n--;
}
int search(char *arr,int n,char key){
	for(int i=0;i<n;i++){
		if(arr[i]==key){
			return i;
		}
	}
	return -1;
}
int main(){
	int n;
	cin>>n;
	char arr[100];
	// for(int i=0;i<n;i++){
	// 	cin>>arr[i];
	// }
	arr[n]='\0';
	cin>>arr;
	// char key;
	// cin>>key;
	// int pos;
	// cin>>pos;
	// insertion(arr,n,key,pos);
	// cout<<arr<<endl;
	// pos=3;
	// deletion(arr,n,pos);
	// cout<<arr<<endl;
	// key='h';
	// cout<<search(arr,n,key)<<endl;
	sort(arr,n);
	cout<<arr<<endl;

	return 0;
}