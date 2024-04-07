class Solution {
public:
    int helper(TreeNode* root,int sum){
        if(root==NULL){
            return 0;
        }
        sum=sum*10+root->val;
        if(root->left==NULL&&root->right==NULL){
            return sum;
        }
        int left=helper(root->left,sum);
        int right=helper(root->right,sum);
        return left+right;
    }
    int sumNumbers(TreeNode* root) {
        return helper(root,0);
    }
};