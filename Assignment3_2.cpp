#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

int N, L, W;
int lower_vertex, upper_vertex;

class Graph {
private:
    int V;
    list<int> *adj;
    void DFSUtil(int s, std::vector<bool> &visited) {
        visited[s] = true;
        list<int>::iterator i;
        for(i = adj[s].begin(); i != adj[s].end(); i++) {
            if(!visited[*i]) DFSUtil(*i, visited);
        }
    }
public:
    Graph(int V) {
        this -> V = V;
        adj = new list<int>[V];
    }
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }
    void DFS(int s) {
        std::vector<bool> visited(V, 0);
        DFSUtil(s, visited);
    }
    int BFS(int s) {
        std::vector<bool> visited(V, 0);
        list<int> queue;
        visited[s] = true;
        queue.push_back(s);
        list<int>::iterator i;
        while(!queue.empty()) {
            s = queue.front();
            cout << s << " ";
            queue.pop_front();
            for(i = adj[s].begin(); i != adj[s].end(); i++) {
                if(!visited[*i]) {
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            }
        }
        int count = 0;
        for(int i = 0; i < V; i++) {
            if(visited[i] == false)
            count++;
        }
        if(visited[upper_vertex] == false || visited[lower_vertex] == false) return 1;
        return 0;
    }
};


int dist(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void connect(Graph &g, int a[][2]) {
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; i++) {
            if(dist(a[i][0], a[i][1], a[j][0], a[j][1]) <= 200) {
                g.addEdge(i, j);
            }
        }
    }
}

void check(Graph &g, int a[][2]) {
    for(int i = 0; i < N; i++) {
        if(lower_vertex > a[i][1]) {
            lower_vertex = i;
        }
        if(upper_vertex < a[i][1]) {
            upper_vertex = i;
        }
    }
}

int main() {
    cin >> L >> W >> N;
    int a[N][2];
    for(int i = 0; i < N; i++) {
        cin >> a[i][0] >> a[i][1];
        cout << a[i][0] << " " << a[i][1] << endl;
    }
    Graph g(N);
    upper_vertex = lower_vertex = 0;
    check(g, a);
    cout << "Before connect" << endl;
    connect(g, a);
    cout << g.BFS(0) << endl;
    return 0;
}
