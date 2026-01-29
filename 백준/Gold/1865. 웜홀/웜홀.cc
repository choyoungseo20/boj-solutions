#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int s;
	int e;
	int t;
};

vector<Node> graph;

int dist[501];
bool m_cycle;

void bellman_ford(int n) {
	m_cycle = false;
	for (int i = 1; i <= n; i++) dist[i] = 0;

	for (int i = 1; i <= n - 1; i++) {
		for (auto n : graph) {
			dist[n.e] = min(dist[n.e], dist[n.s] + n.t);
		}
	}

	for (auto n : graph) {
		if (dist[n.e] > dist[n.s] + n.t) {
			m_cycle = true;
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;

	while (tc--) {
		graph.clear();

		int n, m, w;
		cin >> n >> m >> w;

		int s, e, t;
		for (int i = 0; i < m; i++) {
			cin >> s >> e >> t;

			graph.push_back({ s, e, t });
			graph.push_back({ e, s, t });
		}

		for (int i = 0; i < w; i++) {
			cin >> s >> e >> t;

			graph.push_back({ s, e, -t });
		}
		
		bellman_ford(n);

		if (m_cycle) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
}