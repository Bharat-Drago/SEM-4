class Solution {
public:
TreeNode* helper(unordered_map<int,int> &mp,vector<int>& preorder,int stp,int endp,vector<int>& inorder,int stin,int endin){
    if(stp>endp||stin>endin){
        return NULL;
    }
    TreeNode* root=new TreeNode(preorder[stp]);
    int idxroot = mp[preorder[stp]];
    int leftsize=idxroot-stin;
    root->left=helper(mp,preorder,stp+1,stp+leftsize,inorder,stin,idxroot-1);
    root->right=helper(mp,preorder,stp+leftsize+1,endp,inorder,idxroot+1,endin);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int m=preorder.size();
        int n=inorder.size();
        return helper(mp,preorder,0,m-1,inorder,0,n-1);
    }
};