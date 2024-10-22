/*Description
Given a undirected graph =(V,E) in which V = {1,2,..,n} is the set of nodes. Write a program that visit nodes of G by a DFS (consider a lexicorgraphic order of nodes).
Input
Line 1: contains 2 integers n and m (1 <= n,m <= 100000)
Line i+1: contains u and v which are two end-points of the ith edge
Output
Sequence of nodes visited by DFS
Example
Input
7 12
1 2
1 3
2 3
2 4
2 7
3 5 
3 7
4 5
4 6
4 7
5 6
5 7 
Output
1 2 3 5 4 6 7*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;
void dfs(int start, unordered_map<int, set<int>>& adj, vector<bool>& visited){
    visited[start]=true;
    cout<<start<<" ";
    for(int neighbor:adj[start]){
        if(!visited[neighbor]){
            dfs(neighbor, adj, visited);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    unordered_map<int,set<int>> adj;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    vector<bool> visited(n+1, false);
     for (int i = 1; i <= n; i++) {
        if (!visited[i] && adj.find(i) != adj.end()) { 
            dfs(i, adj, visited);
        }
    }
    return 0;
}
