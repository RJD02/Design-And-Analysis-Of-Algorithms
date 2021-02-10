#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

int *parent;
int L, W, N;
int upper_val, lower_val;
bool upper_flag, lower_flag;
std::vector<int> ret;
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
        for(int i = 0; i < V; i++) {
            // cout << visited[i] << " ";
            if(visited[i] == true)
            count++;
            // return 0;
        }
        if(count == V) return 1;
        else return 0;
        // cout << endl;
    }
    int getV() {
        return V;
    }
    int getNumberOfEdges() {
        return number_of_edges;
    }
};

// void display(Graph g, int start) {
//     for(int i = start + 1; i < g.getV(); i++) {
//         cout << i << " parent = " << parent[i] << " ";
//     }
//     cout << endl;
// }

// void displayRet() {
//     for(int i = 0; i < ret.size(); i++) {
//         cout << ret[i] << " ";
//     }
//     cout << endl;
// }

int dist(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void connect(std::vector<std::vector<int>> v, Graph &g) {
    for(int i = 0; i < v.size(); i++) {
        for(int j = i + 1; j < v.size(); j++) {
            if(dist(v[i][0], v[i][1], v[j][1], v[j][1]) <= 200) {
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
            lower_val = min(v[i][1], lower_val);
        }
        if(W - v[i][0] <= 100) {
            upper_flag = true;
            upper_val = max(v[i][0], upper_val);
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
            // cout << a[i][0] << " " << a[i][1] << endl;;
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
        // display(g, start);
        // cout << upper_val << " " << lower_val;
        // sort(ret.begin(), ret.end());
        // // displayRet();
        // if(ret[0] == 0 && ret[ret.size() - 1] == upper_val && upper_flag == true && lower_flag == true) {
        //     cout << 0;
        // }
        // else cout << 1;
        // cout << endl << g.getNumberOfEdges();
    }
    return 0;
}
