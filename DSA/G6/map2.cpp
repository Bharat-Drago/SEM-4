#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> vec={9,9,10,7,1,2,2,2,1,4,5,5,8,8,8,6,4,5,5,3};
	vector<int> along={8,2,1,3,4,5,6};
	sort(vec.begin(),vec.end());
	unordered_map<int,int> mp;
	unordered_map<int,int> mp2;
	for(int i=0;i<vec.size();i++){
		mp[vec[i]]++;
	}
	for(int i=0;i<along.size();i++){
		mp2[along[i]]++;
	}
	vector<int> ans;
	for(int i=0;i<along.size();i++){
		if(mp.find(along[i])!=mp.end()){
			for(int j=0;j<mp[along[i]];j++){
				ans.push_back(along[i]);
			}
		}
	}
	for(int i=0;i<vec.size();i++){
		if(mp2.find(vec[i])==mp2.end()){
			ans.push_back(vec[i]);
		}
	}
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}