#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> adj[5001];
bool visited[5001];

long long max_dist = 0;

void dfs(int n, long long dist) {
    for (int i = 0; i < adj[n].size(); i++) {
        if (!visited[adj[n][i].first]) {
            if (max_dist < dist + 1LL * adj[n][i].second) {
                max_dist = dist + 1LL * adj[n][i].second;
            }

            visited[adj[n][i].first] = true;
            dfs(adj[n][i].first, dist + 1LL * adj[n][i].second);
        }
    }
}

int main() {
    int N;
    cin >> N;

    int A, B, C;
    for (int i = 0; i < N - 1; i++) {
        cin >> A >> B >> C;
        adj[A].push_back({ B, C });
        adj[B].push_back({ A, C });
    }

    visited[1] = true;
    dfs(1, 0);

    cout << max_dist;
}