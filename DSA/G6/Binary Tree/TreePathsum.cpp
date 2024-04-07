class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        if(root==NULL&&targetSum!=0){
            return false;
        }
        targetSum-=root->val;
        if(targetSum==0&&root->left==NULL&&root->right==NULL){
            return true;
        }
        return hasPathSum(root->left,targetSum)||hasPathSum(root->right,targetSum);
    }
};