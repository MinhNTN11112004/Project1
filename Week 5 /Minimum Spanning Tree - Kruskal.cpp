/*Description
Given a undirected connected graph G=(V,E) where V={1,…,N}. Each edge (u,v)∈E(u,v)∈E has weight w(u,v)w(u,v). Compute minimum spanning tree of G.
Input
Line 1: N and M (1≤N,M≤10
5
) in which NN is the number of nodes and MM is the number of edges.
Line i+1 (i=1,…,M): contains 3 positive integers u, v, and w where w is the weight of edge (u,v)
Output
Write the weight of the minimum spanning tree found.
Example
Input
5 8
1 2 1
1 3 4
1 5 1
2 4 2
2 5 1
3 4 3
3 5 3
4 5 2
Output
7*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge {
    int u, v, weight;
};
class UnionFind {
public:
    UnionFind(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unionSet(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
private:
    vector<int> parent;
    vector<int> rank;
};
int main() {
    int N, M;
    cin >> N >> M;
    vector<Edge> edges(M);
    for (int i = 0; i < M; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    UnionFind uf(N);
    int mstWeight = 0;
    int edgesUsed = 0;
    for (const Edge& edge : edges) {
        if (uf.find(edge.u) != uf.find(edge.v)) {
            uf.unionSet(edge.u, edge.v);
            mstWeight += edge.weight;
            edgesUsed++;
            if (edgesUsed == N - 1) break; 
        }
    }
    cout << mstWeight << endl;
    return 0;
}
