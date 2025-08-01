#include<bits/stdc++.h>
using namespace std;
class  DisjointSet{
	vector<int>rank,parent,size;
public:
	DisjointSet(int n){
		rank.resize(n+1,0);
		parent.resize(n+1);
		size.resize(n+1);
		for(int i=0;i<=n;i++){
			parent[i]=i;
			size[i]=1;
		}
	}

	int findUPar(int node){
		if(node==parent[node]){
			return node;
		}
		return parent[node]=findUPar(parent[node]);
	}

	void unionByRank(int u,int v){
		int pu=findUPar(u);
		int pv=findUPar(v);
		if(pu==pv){
			return;
		}
		if(rank[pu]<rank[pv]){
			parent[pu]=pv;
		}
		else if(rank[pv]>rank[pu]){
			parent[pv]=pu;
		}
		else{
			parent[pv]=pu;
			rank[pu]++;
		}
	}

	void unionBySize(int u,int v){
		int pu=findUPar(u);
		int pv=findUPar(v);
		if(pu==pv){
			return;
		}
		if(size[pu]<size[pv]){
			parent[pu]=pv;
			size[pv]+=size[pu];
		}
		else{
			parent[pv]=pu;
			size[pu]+=size[pv];
		}
	}
};