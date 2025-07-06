#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void floydWarshall(int V,vector<vector<int>>&grid){
        int n=grid.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==-1){
                    grid[i][j]=1000000;
                }
            }
        }

        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    grid[i][j]=min(grid[i][j],grid[i][via]+grid[via][j]);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1000000){
                    grid[i][j]=-1;
                }
            }
        }
    }
};