#include<bits/stdc++.h>
using namespace std;
class trienode{
public:
	trienode* letters[26];
	bool end;
	trienode(){
		for(int i=0;i<26;i++){
			letters[i]=NULL;
		}
		end=false;
	}
};
void insert(trienode* root,string str){
	trienode* temp=root;
	for(int i=0;i<str.size();i++){
		int idx=str[i]-'a';
		if(temp->letters[idx]==NULL){
			temp->letters[idx]=new trienode();
		}
		temp=temp->letters[idx];
	}
	temp->end=true;
}
bool search(trienode* root,string str){
	trienode* temp=root;
	for(int i=0;i<str.size();i++){
		int idx=str[i]-'a';
		if(temp->letters[idx]==NULL){
			return false;
		}
		temp=temp->letters[idx];
	}
	return temp->end;
}
bool prefix(trienode* root,string str){
	trienode* temp=root;
	for(int i=0;i<str.size();i++){
		int idx=str[i]-'a';
		if(temp->letters[idx]==NULL){
			return false;
		}
		temp=temp->letters[idx];
	}
	return true;
}
int main(){
	trienode* root=new trienode();
	insert(root,"bharat");
	insert(root,"bhanu");
	insert(root,"keshav");
	insert(root,"keju");
	insert(root,"kesh");
	cout<<prefix(root,"bha");
	return 0;
}