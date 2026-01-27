#include <iostream>
#include <vector>

using namespace std;

int dist[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dist[i][j] == 0;
			else dist[i][j] = 987654321;
		}
	}

	int u, v, c;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> c;

		dist[u][v] = min(dist[u][v], c);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == 987654321) dist[i][j] = 0;
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
}