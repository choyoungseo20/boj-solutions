#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> adj[100001];
priority_queue<pair<int, int>> pq;
int max_weight[100001];

void dijkstra(int s) {
	max_weight[s] = 1234567890;
	pq.push({ 1234567890, s });

	while (!pq.empty()) {
		int w = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		if (max_weight[x] > w) continue;

		for (int i = 0; i < adj[x].size(); i++) {
			int nw = min(adj[x][i].second, w);
			int nx = adj[x][i].first;

			if (nw > max_weight[nx]) {
				max_weight[nx] = nw;
				pq.push({ nw, nx });
			}
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;

		adj[A].push_back({ B, C });
		adj[B].push_back({ A, C });
	}

	int s, e;
	cin >> s >> e;

	dijkstra(s);

	cout << max_weight[e];
}