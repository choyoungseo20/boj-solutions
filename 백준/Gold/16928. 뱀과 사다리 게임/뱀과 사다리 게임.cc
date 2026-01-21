#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visited[101];
int jump[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;;

	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		jump[x] = y;
	}

	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		jump[u] = v;
	}

	queue<pair<int, int>> q;
	q.push({ 1, 0 });
	visited[1] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int d = q.front().second;
		q.pop();

		if (x == 100) {
			cout << d;
			break;
		}

		for (int i = 1; i <= 6; i++) {
			int nx = x + i;
			int nd = d + 1;

			if (nx > 100) continue;
			if (jump[nx]) {
				if (visited[jump[nx]]) continue;
				q.push({ jump[nx], nd });
				visited[jump[nx]] = true;
			}
			else {
				if (visited[nx]) continue;
				q.push({ nx, nd });
				visited[nx] = true;
			}
		}
	}
}