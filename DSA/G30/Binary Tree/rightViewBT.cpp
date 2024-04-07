class Solution {
public:
    void helper(TreeNode* root,vector<int> &ans,int level){
        if(root==NULL){
            return;
        }
        if(ans.size()==level){
            ans.push_back(root->val);
        }
        helper(root->right,ans,level+1);
        helper(root->left,ans,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<int> ans;
        helper(root,ans,0);
        return ans;
    }
};