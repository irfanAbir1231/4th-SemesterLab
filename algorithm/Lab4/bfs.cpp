#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m; 
    cin >> n >> m;

    vector<vector<int>> graph(n+1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        cout<<u<<" "<<v<<endl;
    graph[u].push_back(v);
    graph[v].push_back(u);
    }

    int start; 
    cin >> start;

    cout << "BFS Traversal starting from node " << start << ": ";
    bfs(graph, start);
    cout << endl;

    return 0;
}
