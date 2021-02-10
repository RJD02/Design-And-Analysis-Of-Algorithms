#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int N = 1, L, W;
int upper_vertex = 0, lower_vertex = 0;
int upper_val = -INT_MAX, lower_val = INT_MAX;
// upper_vertex = lower_vertex = 0;

class Graph {
private:
    int V;
    list<int> *adj;
    int number_of_edges;
    void DFSUtil(int s, std::vector<bool> &visited) {
        visited[s] = true;
        // cout << s << " ";
        list<int>::iterator i;
        for(i = adj[s].begin(); i != adj[s].end(); i++) {
            if(!visited[*i]) {
                DFSUtil(*i, visited);
            }
        }
    }
public:
    Graph(int V) {
        this -> V = V;
        adj = new list<int>[V];
        number_of_edges++;
    }
    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
    int getV() {return V;}
    int getNumberOfEdges() {return number_of_edges;}
    int DFS(int s) {
        int count = 0;
        std::vector<bool> visited(V, 0);
        DFSUtil(s, visited);
        for(int i = 0; i < V; i++) {
            if(!visited[i]) count++;
        }
        // cout << count << endl;
        if(visited[upper_vertex] == false || visited[lower_vertex] == false || number_of_edges < V) return 0;
        return 1;
    }
};

int dist(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void connect(Graph &g, int a[][2]) {
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(dist(a[i][0], a[i][1], a[j][0], a[j][1]) <= 200) {
                g.addEdge(i, j);
            }
        }
    }
}

void check(Graph &g, int a[][2]) {
    for(int i = 0; i < N; i++) {
        if(a[i][0] <= 100 && a[i][0] <= lower_val) {
            lower_vertex = i;
        }
        if(a[i][1] - W <= 100 && a[i][1] >= upper_val) {
            upper_vertex = i;
        }
    }
}

int main() {
    cin >> L >> W >> N;
    int a[N][2];
    for(int i = 0; i < N; i++) {
        cin >> a[i][0] >> a[i][1];
        // cout << a[i][0] << " " << a[i][1] << endl;
    }
    Graph g(N);
    connect(g, a);
    // g.DFS(0);
    // cout << endl;
    check(g, a);
    cout << g.DFS(0);
    // cout << "Case#" << t << ": " << g.DFS(0) << endl;
    return 0;
}
