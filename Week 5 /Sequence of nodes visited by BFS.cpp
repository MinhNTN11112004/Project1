/*Description
Given undirected graph G = (V,E) in which V = {1, 2, ..., n} is the set of nodes, and E is the set of m edges.
Write a program that computes the sequence of nodes visited using a BFS algorithm (the nodes are considered in a lexicographic order)
Input
Line 1: contains 2 integers n and m which are the number of nodes and the number of edges
Line i+1 (i = 1, ..., m): contains 2 positive integers u and v which are the end points of the ith edge
Output
Write the sequence of nodes visited by a BFS procedure (nodes a are separated by a SPACE character)
Example
Input
6 7
2 4
1 3
3 4
5 6
1 2
3 5
2 3
Output
1 2 3 4 5 6*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;
void bfs(int start, unordered_map<int, set<int>>& adj, vector<bool>& visited){
    queue<int> q;
    vector<int> bfs_order;
    q.push(start);
    visited[start]=true;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs_order.push_back(node);
        for (int neighbor : adj.at(node)) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    for (int i = 0; i < bfs_order.size(); i++) {
        cout << bfs_order[i]<<" "; 
    }
    cout << endl;
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
    vector<bool> visited(n, false);
     for (int i = 1; i <= n; i++) {
        if (!visited[i] && adj.find(i) != adj.end()) { 
            bfs(i, adj, visited);
        }
    }
    return 0;
}
