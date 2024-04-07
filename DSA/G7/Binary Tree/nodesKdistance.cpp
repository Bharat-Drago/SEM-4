class Solution {
public:
    void helper(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &mp){
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> mp;
        helper(root,mp);
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        int count=0;
        while(!q.empty()){
            int size=q.size();
            if(count==k){
                break;
            }
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
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};