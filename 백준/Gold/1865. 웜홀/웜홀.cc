#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node {
	int s;
	int e;
	int t;
};

vector<Node> graph;
unordered_map<int, int> hm;

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
		hm.clear();
		graph = vector<Node>();

		int n, m, w;
		cin >> n >> m >> w;

		int s, e, t;
		for (int i = 0; i < m; i++) {
			cin >> s >> e >> t;

			if (hm[s * 1000 + e] != 0) {
				hm[s * 1000 + e] = min(hm[s * 1000 + e], t);
			}
			else hm[s * 1000 + e] = t;

			if (hm[e * 1000 + s] != 0) {
				hm[e * 1000 + s] = min(hm[e * 1000 + s], t);
			}
			else hm[e * 1000 + s] = t;
		}

		for (int i = 0; i < w; i++) {
			cin >> s >> e >> t;

			if (hm[s * 1000 + e] != 0) {
				hm[s * 1000 + e] = min(hm[s * 1000 + e], -1 * t);
			}
			else hm[s * 1000 + e] = -1 * t;
		}

		for (auto a : hm) {
			s = a.first / 1000;
			e = a.first % 1000;
			graph.push_back({ s, e, a.second });
		}
		
		bellman_ford(n);

		if (m_cycle) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
}