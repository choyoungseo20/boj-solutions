#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;

vector<pair<int, int>> adj[1001];
int cost[1001];
vector<int> path[1001];

int n, m;

void dijkstra(int s) {
	for (int i = 1; i <= n; i++) cost[i] = INF;

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, s });
	cost[s] = 0;
	path[s].push_back(s);

	while (!pq.empty()) {
		int x = pq.top().second;
		int c = pq.top().first;
		pq.pop();

		if (cost[x] < c) continue;

		for (int i = 0; i < adj[x].size(); i++) {
			int nx = adj[x][i].first;
			int nc = adj[x][i].second + c;

			if (cost[nx] <= nc) continue;

			cost[nx] = nc;
			path[nx] = path[x];
			path[nx].push_back(nx);
			pq.push({ nc, nx });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;

	int s, e, c;
	for (int i = 0; i < m; i++) {
		cin >> s >> e >> c;

		adj[s].push_back({ e, c });
	}

	cin >> s >> e;

	dijkstra(s);

	cout << cost[e] << "\n";
	cout << path[e].size() << "\n";
	for (int i = 0; i < path[e].size(); i++) {
		cout << path[e][i] << " ";
	}
}