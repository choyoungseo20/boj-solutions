#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int, int>> adj[1001];
int cost[1001][1001];

int N, P, K;

void dijkstra(int n) {
    for (int i = 1; i <= N; i++) fill(cost[i], cost[i] + N, 123456789);

    priority_queue < pair<int, pair<int, int>>, vector < pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({ 0, {n, 0} });
    cost[n][0] = 0;

    while (!pq.empty()) {
        int c = pq.top().first;
        int x = pq.top().second.first;
        int free_cnt = pq.top().second.second;
        pq.pop();

        if (cost[x][free_cnt] < c) continue;

        for (int i = 0; i < adj[x].size(); i++) {
            int nx = adj[x][i].first;
            int nc = adj[x][i].second;

            if (c < nc) {
                if (free_cnt < K) {
                    if (cost[nx][free_cnt + 1] > c) {
                        pq.push({ c, {nx, free_cnt + 1} });
                        cost[nx][free_cnt + 1] = c;
                    }
                }
                if (cost[nx][free_cnt] > nc) {
                    pq.push({ nc, {nx, free_cnt} });
                    cost[nx][free_cnt] = nc;
                }
            }
            else {
                if (cost[nx][free_cnt] > c) {
                    pq.push({ c, {nx, free_cnt} });
                    cost[nx][free_cnt] = c;
                }
            }
        }

    }
}

int main() {
    cin >> N >> P >> K;

    int a, b, c;
    for (int i = 0; i < P; i++) {
        cin >> a >> b >> c;

        adj[a].push_back({ b, c });
        adj[b].push_back({ a, c });
    }

    dijkstra(1);

    int ans = 123456789;
    for (int i = 0; i < N; i++) ans = min(ans, cost[N][i]);

    if (ans == 123456789) cout << -1;
    else cout << ans;
}