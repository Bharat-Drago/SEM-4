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
TreeNode* BiuldTree(vector<int> &vec,int n){
	if(n==0||vec[0]==-1){
		return NULL;
	}
	TreeNode* root=new TreeNode(vec[0]);
	queue<TreeNode*> q;
	q.push(root);
	int i=1;
	while(!q.empty()&&i<n){
		TreeNode* node=q.front();
		q.pop();
		if(vec[i]!=-1){
			node->left=new TreeNode(vec[i]);
			q.push(node->left);
		}
		i++;
		if(i>=n){
			break;
		}
		if(vec[i]!=-1){
			node->right=new TreeNode(vec[i]);
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
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++){
		cin>>vec[i];
	}
	TreeNode* root=BiuldTree(vec,n);
	inorder(root);
}