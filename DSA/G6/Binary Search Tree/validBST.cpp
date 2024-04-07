class Solution {
public:
    bool valid(TreeNode* root,long long mn,long long mx){
        if(root==NULL){
            return true;
        }
        if(root->val>=mx||root->val<=mn){
            return false;
        }
        return valid(root->left,mn,root->val)&&valid(root->right,root->val,mx);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        long long maxx=INT_MAX;
        long long minn=INT_MIN;

        return valid(root,minn-1,maxx+1);
    }
};