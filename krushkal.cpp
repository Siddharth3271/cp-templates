#include <bits/stdc++.h>
using namespace std;
//krushkal's algorithm
vector<int> parent;
int find(int x)
{
    if (x == parent[x])
    {
        return x;
    }
    return parent[x] = find(parent[x]);
}
void Union(int x, int y)
{
    int x_parent = find(x);
    int y_parent = find(y);
    if (x_parent != y_parent)
    {
        parent[x_parent] = y_parent;
    }
}
int krushkal(vector<vector<int>> &vec)
{
    int sum = 0;
    for (auto &temp : vec)
    {
        int u = temp[0];
        int v = temp[1];
        int wt = temp[2];
        int parent_u = find(u);
        int parent_v = find(v);
        if (parent_u != parent_v)
        {
            // if they are disconnected
            Union(u, v);
            sum += wt;
        }
    }
    return sum;
}
// Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, unordered_map<int, vector<pair<int, int>>>&adj)
{
    parent.resize(V);
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }
    vector<vector<int>> vec;
    for (int u = 0; u < V; u++)
    {
        for (auto &temp : adj[u])
        {
            int v = temp.first;
            int wt = temp.second;
            vec.push_back({u, v, wt});
        }
    }
    auto comparator = [&](vector<int> &vec1, vector<int> &vec2)
    {
        return vec1[2] > vec2[2];
    };
    sort(vec.begin(), vec.end(), comparator);
    return krushkal(vec);
}

int main() {
    int n;
    cin >> n;
    unordered_map<int, vector<pair<int, int>>>adj;
    vector<bool>visited(n + 1, false);
    vector<vector<int>> matrix(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (matrix[i][j] != 0) {
                adj[i].push_back({j, matrix[i][j]});
                adj[j].push_back({i, matrix[i][j]});
            }
        }
    }
    int ans = spanningTree(n, adj);
    cout << "Sum of weights of edges of the Maximum Spanning Tree: " << ans << endl;
    return 0;
}
