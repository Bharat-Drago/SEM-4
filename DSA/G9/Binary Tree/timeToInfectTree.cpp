class Solution {
public:
    void helper(TreeNode* root,int start,TreeNode* &target){
        if(root==NULL){
            return;
        }
        if(root->val==start){
            target=root;
            return;
        }
        helper(root->left,start,target);
        helper(root->right,start,target);
    } 
    void mark_parent(unordered_map<TreeNode*,TreeNode*> &mp,TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    mp[node->left]=node;
                }
                if(node->right){
                    q.push(node->right);
                    mp[node->right]=node;
                }
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* target;
        helper(root,start,target);
        unordered_map<TreeNode*,TreeNode*> mp;
        mark_parent(mp,root);
        unordered_map<TreeNode*,bool> visited;
        int count=0;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left&&!visited[node->left]){
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right&&!visited[node->right]){
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(mp[node]&&!visited[mp[node]]){
                    q.push(mp[node]);
                    visited[mp[node]]=true;
                }
            }
            count++;
        }
        return count-1;
    }
};