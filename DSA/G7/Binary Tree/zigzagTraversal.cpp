class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        bool flag=true;
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()){
            int size=q.size();
            vector<int> vec;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                vec.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(flag==false){
                reverse(vec.begin(),vec.end());
            }
            ans.push_back(vec);
            flag=!flag;
        }
        return ans;
    }
};