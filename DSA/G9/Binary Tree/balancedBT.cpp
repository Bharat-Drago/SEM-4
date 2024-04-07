class Solution {
public:
    int helper(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left=helper(root->left);
        int right=helper(root->right);
        if(left==-1||right==-1){
            return -1;
        }
        if(abs(left-right)>1){
            return -1;
        }
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        return helper(root)!=-1;
    }
};