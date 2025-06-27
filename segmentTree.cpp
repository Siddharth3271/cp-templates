#include<iostream>
#include<vector>
using namespace std;
class SegmentTree{
private:
    //0 based indexing
    vector<int>tree;
    int n;
    void build(vector<int>&arr,int index,int left,int right){
        if(left==right){
            tree[index]=arr[left];
            return;
        }

        int mid=(left+right)/2;

        build(arr,2*index+1,left,mid);
        build(arr,2*index+2,mid+1,right);

        //sum query after both build queries
        tree[index]=tree[2*index+1]+tree[2*index+2];
    }

    void update(int index,int left,int right,int pos,int value){
        if(left==right){
            tree[index]=value;
            return;
        }

        int mid=(left+right)/2;
        if(pos<=mid){
            update(2*index+1,left,mid,pos,value);
        }
        else{
            update(2*index+2,mid+1,right,pos,value);
        }
        tree[index]=tree[2*index+1]+tree[2*index+2];
    }
    //[l,r]->given query range
    int query(int index,int left,int right,int l,int r){
        if(r<left || l>right) return 0;  //no overlap
        if(l<=left && right<=r) return tree[index];  //total overlap
        int mid=(left+right)/2;
        return query(2*index+1,left,mid,l,r)+query(2*index+2,mid+1,right,l,r);
    }

public:
    SegmentTree(vector<int>&arr){
        n=arr.size();
        tree.resize(4*n);
        build(arr,0,0,n-1);
    }

    void pointUpdate(int pos,int value){
        update(0,0,n-1,pos,value);
    }
    int rangeQuery(int l,int r){
        return query(0,0,n-1,l,r);
    }
};