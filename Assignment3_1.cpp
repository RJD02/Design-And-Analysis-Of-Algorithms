#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

int *parent;
int L, W, N;
int upper_val, lower_val;
bool upper_flag, lower_flag;
std::vector<int> ret;
int lower_vertex = 0, upper_vertex = 0;
class Graph {
private:
    int V;
    int number_of_edges;
    list<int> *adj;
    void DFSUtil(int s, std::vector<bool> &visited) {
        // std::vector<int> ret;
        visited[s] = true;
        list<int>::iterator i;
        // cout << s << " ";
        ret.push_back(s);
        for(i = adj[s].begin(); i != adj[s].end(); i++) {
            if(!visited[*i]) {
                parent[*i] = s;
                // cout << parent[*i];
                DFSUtil(*i, visited);
            }
        }
        // return ret;
    }
public:
    Graph(int v) {
        V = v;
        adj = new list<int>[V];
        parent = new int[V];
        number_of_edges = -1;
    }
    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
        number_of_edges++;
    }
    int DFS(int s) {
        std::vector<bool> visited(V, 0);
        DFSUtil(s, visited);
        int count = 0;
        if(visited[upper_vertex] == false) return 1;
        return 0;
    }
    int getV() {
        return V;
    }
    int getNumberOfEdges() {
        return number_of_edges;
    }
};

int dist(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void connect(std::vector<std::vector<int>> v, Graph &g) {
    for(int i = 0; i < v.size(); i++) {
        for(int j = i + 1; j < v.size(); j++) {
            if(dist(v[i][0], v[i][1], v[j][1], v[j][1]) < 200) {
                g.addEdge(i, j);
            }
            // if(abs(v[i][0] - v[j][0]) <= 100 && abs(v[j][0] - v[i][0]) <= 100) {
            //     g.addEdge(i, j);
            // }
        }
    }
}

void check(std::vector<std::vector<int>> v, Graph &g) {
    //Check if any of the vertices have range that touches the upper or lower border.
    for(int i = 0; i < v.size(); i++) {
        if(v[i][1] <= 100) {
            lower_flag = true;
            // lower_val = min(v[i][1], lower_val);
            if(lower_val < v[i][1]) {
                lower_val = v[i][1];
                lower_vertex = i;
            }
        }
        if(W - v[i][0] <= 100) {
            upper_flag = true;
            // upper_val = max(v[i][0], upper_val);
            if(upper_val < v[i][0]) {
                upper_val = v[i][0];
                upper_vertex = i;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int start = 0;
        cin >> L >> W >> N;
        std::vector<std::vector<int>> a(N);
        for(int i = 0; i < N; i++) {
            int x, y;
            cin >> x >> y;
            a[i].push_back(y);
            a[i].push_back(x);
            cout << a[i][0] << " " << a[i][1] << endl;;
        }
        Graph g(N);
        connect(a, g);
        check(a, g);
        cout << g.getNumberOfEdges() << " ";
        if(g.getNumberOfEdges() == 0) {
            cout << "Case#" << t << ":" << 1 << endl;
            return 0;
        }
        cout << "Case#" << t << ": " << g.DFS(lower_val) << endl;
    }
    return 0;
}
