#include<bits/stdc++.h>
using namespace std;
//topological sort using bfs(kahn's algorithm)
vector<int> output(vector<int>&ans){
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
void solve(unordered_map<int,vector<int>>&mp,int V){
    vector<int>indegree(V+1);
    for(int i=1;i<=V;i++){
        for(auto &it:mp[i]){
            indegree[it]++;
        }
    }
    queue<int>qu;
    vector<int>ans;
    for(int i=1;i<=V;i++){
        if(indegree[i]==0){
            qu.push(i);
        }
    }
    while(!qu.empty()){
        int node=qu.front();
        qu.pop();
        ans.push_back(node);
        for(auto &it:mp[node]){
            indegree[it]--;
            if(indegree[it]==0){
                qu.push(it);
            }
        }
    }
    output(ans);
}
int main(){
    int V,e;
    cin>>V>>e;
    unordered_map<int,vector<int>>mp;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        mp[u].push_back(v);
    }
    solve(mp,V);
    return 0;
}