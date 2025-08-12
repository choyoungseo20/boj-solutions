#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[500001];
bool visited[500001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int n1, n2;
    for (int i = 0; i < N - 1; i++) {
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    queue<pair<int, int>> q;

    q.push({ 1, 0 });
    visited[1] = true;

    int cnt = 0;
    while (!q.empty()) {
        int n = q.front().first;
        int dist = q.front().second;
        q.pop();

        bool leaf = true;
        for (auto v : adj[n]) {
            if (!visited[v]) {
                leaf = false;
                visited[v] = true;
                q.push({ v, dist + 1 });
            }
        }
        if (leaf) cnt += dist;
    }

    if (cnt % 2 == 1) cout << "Yes";
    else cout << "No";
}