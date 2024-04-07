class Solution {
public:
    TreeNode* helper(TreeNode* root){
        if(root->left==NULL){
            return root->right;
        }
        if(root->right==NULL){
            return root->left;
        }
        TreeNode* delright=root->right;
        TreeNode* rightMost=root->left;
        while(rightMost->right){
            rightMost=rightMost->right;
        }
        rightMost->right=delright;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==key){
            return helper(root);
        }
        TreeNode* temp=root;
        while(temp){
            if(temp->val>key){
                if(temp->left&&temp->left->val==key){
                    temp->left=helper(temp->left);
                    break;
                }
                else{
                    temp=temp->left;
                }
            }
            else{
                if(temp->right&&temp->right->val==key){
                    temp->right=helper(temp->right);
                    break;
                }
                else{
                    temp=temp->right;
                }
            }
        }
        return root;
    }
};