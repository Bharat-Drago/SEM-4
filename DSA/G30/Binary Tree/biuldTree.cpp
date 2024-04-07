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
TreeNode* buildTree(){
	int data;
	cin>>data;
	TreeNode* root=new TreeNode(data);
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()){
		int size=q.size();
		for(int i=0;i<size;i++){
			TreeNode* node=q.front();
			q.pop();
			int left,right;
			cin>>left>>right;
			if(left!=-1){
				node->left=new TreeNode(left);
				q.push(node->left);
			}
			if(right!=-1){
				node->right=new TreeNode(right);
				q.push(node->right);
			}
		}
	}
	return root;
}
void preorder(TreeNode* root){
	if(root==NULL){
		return;
	}
	cout<<root->val<<" ";
	preorder(root->left);
	preorder(root->right);
}
int main(){
	TreeNode* root=buildTree();
	preorder(root);
	return 0;
}