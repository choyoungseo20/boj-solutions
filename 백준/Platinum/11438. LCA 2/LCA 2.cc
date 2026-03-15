#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100001;
const int LOG = 17; // 2^17 > 100000

vector<int> adj[MAX];
bool visited[MAX];
int parent[MAX][LOG];
int depth[MAX];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int n = q.front();
        q.pop();

        for (auto nn : adj[n]) {
            if (visited[nn]) continue;

            visited[nn] = true;
            depth[nn] = depth[n] + 1;
            parent[nn][0] = n;
            q.push(nn);
        }
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);

    int diff = depth[a] - depth[b];

    for (int i = 0; i < LOG; i++) {
        if (diff & (1 << i))
            a = parent[a][i];
    }

    if (a == b) return a;

    for (int i = LOG - 1; i >= 0; i--) {
        if (parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    return parent[a][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a, b;

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1);

    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
}