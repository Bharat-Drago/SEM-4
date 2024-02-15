//Letter combinations of Phone Number -Q17-leetcode

class Solution {
public:
void helper(int idx,vector<string> &ans,unordered_map<char,string> &mp,string &dig,string osf){
    if(idx==dig.size()){
        ans.push_back(osf);
    }
    for(int i=0;i<mp[dig[idx]].size();i++){
        helper(idx+1,ans,mp,dig,osf+mp[dig[idx]][i]);
    }
}
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return {};
        }
        unordered_map<char,string> mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        string osf="";
        vector<string> ans;
        helper(0,ans,mp,digits,osf);
        return ans;
    }
};