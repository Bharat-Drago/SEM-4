#include<iostream>
#include<queue>
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
void preorder(TreeNode* root){
	if(root==NULL){
		return;
	}
	cout<<root->val<<" ";
	if(root->left){
		preorder(root->left);
	}
	if(root->right){
		preorder(root->right);
	}
}
void inorder(TreeNode* root){
	if(root==NULL){
		return;
	}
	
	if(root->left){
		inorder(root->left);
	}
	cout<<root->val<<" ";
	if(root->right){
		inorder(root->right);
	}
}
void postorder(TreeNode* root){
	if(root==NULL){
		return;
	}
	
	if(root->left){
		postorder(root->left);
	}
	if(root->right){
		postorder(root->right);
	}
	cout<<root->val<<" ";
}
void levelorder(TreeNode* root){
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()){
		int size=q.size();
		for(int i=0;i<size;i++){
			TreeNode* temp=q.front();
			q.pop();
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
			cout<<temp->val<<" ";
		}
	}
	cout<<endl;
}
int main(){
	TreeNode* root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(3);
	root->left->left=new TreeNode(4);
	root->left->right=new TreeNode(5);
	root->right->left=new TreeNode(6);
	root->right->right=new TreeNode(7);
	preorder(root);
	cout<<endl;
	inorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	levelorder(root);
	return 0;
}