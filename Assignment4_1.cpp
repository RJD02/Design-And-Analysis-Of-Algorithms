#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
// int max = 0;
class Graph {
    int V;
    list<pair<int, int>> *adj;
public:
    Graph(int M) {
        V = 10000;
        adj = new list<pair<int, int>>[V];
    }
    // void setV(int max) {
    //     V = max;
    //     adj = new list<pair<int, int>>[V];
    // }
    void addEdge(int u, int wt, int v) {
        adj[u].push_back(make_pair(v, wt));
        adj[v].push_back(make_pair(u, wt));
    }
    int getMinVertex(int dist[], bool visited[]) {
        int minvert = -1;
        for(int i = 0; i < V; i++) {
            if(!visited[i] && (minvert == -1 || dist[i] < dist[minvert])) minvert = i;
        }
        return minvert;
    }
    void findPath(int src, int dest, int par[]) {
        std::vector<int> path;
        for(int i = dest; i != -1; i = par[i]) {
            path.push_back(i);
        }
        reverse(path.begin(), path.end());
        cout << path[dest];
        // for(auto x : path)
        // cout << x << " ";
    }
    int dijkstra(int src, int dest) {
        bool visited[V];
        memset(visited, false, sizeof(visited));
        int dist[V];
        for(int i = 0; i < V; i++) dist[i] = INT_MAX;
        dist[src] = 0;
        int par[V];// Parent array
        memset(par, 0, sizeof(par));
        par[src] = -1;

        for(int i = 0; i <V; i++) {
            int u = getMinVertex(dist, visited);
            visited[u] = true;
            for(auto edge : adj[u]) {
                int v = edge.first;
                int wt = edge.second;
                if(!visited[v]) {
                    if (dist[u] + wt < dist[v]) {
                        dist[v] = dist[u] + wt;
                        par[v] = u;
                    }
                }
            }
        }
        for(int i = 0; i < V; i++) {
            for(auto edge : adj[i]) {
                int v = edge.first;
                if(!visited[v]) par[v] = -1;
            }
        }
        // cout << "Distances are: " << endl;
        // for(int i = 0; i < V; i++) {
        //     cout << i << " " << dist[i] << endl;
        // }
        return dist[dest];
        // cout << "Path: " << endl;
        // findPath(src, dest, par);
    }
};

int main() {
    int M, src, dest;
    cin >> M >> src >> dest;
    Graph g(M);
    for(int i = 0; i < M; i++) {
        int u, w, v;
        cin >> u >> w >> v;
        // max = max(u, v, max);
        g.addEdge(u, w, v);
    }
    int cost = g.dijkstra(src, dest);
    if(cost == INT_MAX) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl << cost;
    return 0;
}
