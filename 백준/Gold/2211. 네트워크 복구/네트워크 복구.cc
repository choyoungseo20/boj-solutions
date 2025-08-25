#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int>> adj[1001];
int cost[1001];
int parent[1001];

int N, M;

void dijkstra(int n) {
    fill(cost, cost + N + 1, 123456789);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({ 0, n });
    cost[n] = 0;

    while (!pq.empty()) {
        int c = pq.top().first;
        int x = pq.top().second;
        pq.pop();

        if (cost[x] < c) continue;

        for (int i = 0; i < adj[x].size(); i++) {
            int nx = adj[x][i].first;
            int nc = c + adj[x][i].second;

            if (cost[nx] > nc) {
                pq.push({ nc, nx });
                cost[nx] = nc;
                parent[nx] = x;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    int A, B, C;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;

        adj[A].push_back({ B, C });
        adj[B].push_back({ A, C });
    }

    dijkstra(1);

    cout << N - 1 << "\n";
    for (int i = 2; i <= N; i++) {
        cout << i << " " << parent[i] << "\n";
    }
}