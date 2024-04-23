class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        s.erase(beginWord);
        while(!q.empty()){
            string cur=q.front().first;
            int level=q.front().second;
            q.pop();
            if(cur==endWord){
                return level;
            }
            for(int i=0;i<cur.size();i++){
                char rem=cur[i];
                for(char ch='a';ch<='z';ch++){
                    cur[i]=ch;
                    if(s.find(cur)!=s.end()){
                        q.push({cur,level+1});
                        s.erase(cur);
                    }
                }
                cur[i]=rem;
            }
        }
        return 0;
    }
};