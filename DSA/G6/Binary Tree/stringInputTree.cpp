#include<bits/stdc++.h>
using namespace std;
class TreeNode{
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x){
		val=x;
		left=NULL;
		right=NULL;
	}
};
TreeNode* BiuldTree(vector<string> &vec){
	int n=vec.size();
	if(n==0||vec[0]=="NULL"){
		return NULL;
	}
	TreeNode* root=new TreeNode(stoi(vec[0]));
	queue<TreeNode*> q;
	q.push(root);
	int i=1;
	while(!q.empty()&&i<n){
		TreeNode* node=q.front();
		q.pop();
		if(vec[i]!="NULL"){
			node->left=new TreeNode(stoi(vec[i]));
			q.push(node->left);
		}
		i++;
		if(i>=n){
			break;
		}
		if(vec[i]!="NULL"){
			node->right=new TreeNode(stoi(vec[i]));
			q.push(node->right);
		}
		i++;
	}
	return root;
}
void inorder(TreeNode* root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}
int main(){
	string s;
	getline(cin,s);
	stringstream ss(s);
	string word;
	vector<string> vec;
	while(ss>>word){
		vec.push_back(word);
	}
	TreeNode* root=BiuldTree(vec);
	inorder(root);
}