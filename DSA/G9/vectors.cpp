#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
vector<vector<int>> threesum(vector<int> vec){
	vector<vector<int>> ans;
	set<vector<int>> st;
	for(int i=0;i<vec.size();i++){
		for(int j=i+1;j<vec.size();j++){
			for(int k=j+1;k<vec.size();k++){
				if(vec[i]+vec[j]+vec[k]==0){
					vector<int> temp;
					temp.push_back(vec[i]);
					temp.push_back(vec[j]);
					temp.push_back(vec[k]);
					st.insert(temp);
				}
			}
		}
	}
	// set<vector<int>> :: iterator it;
	for(auto it:st){
		ans.push_back(it);
	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	vector<int> vec;
	for(int i=0;i<n;i++){
		cin>>vec[i];
	}
	vector<vector<int>> ans=threesum(vec);
	cout<<"[";
	for(int i=0;i<ans.size();i++){
		cout<<"[";
		for(int j=0;j<ans[0].size();j++){
			cout<<ans[i][j]<<",";
		}
		cout<<"]";
	}
	cout<<"]";
	return 0;
}