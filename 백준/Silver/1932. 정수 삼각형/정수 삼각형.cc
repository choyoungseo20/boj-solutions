#include <iostream>
#include <queue>

using namespace std;

int dist[501][501];
int tri[501][501];

int n;
int ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> tri[i][j];
		}
	}

	for (int i = n - 1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			tri[i][j] += max(tri[i + 1][j], tri[i + 1][j + 1]);
		}
	}
	
	cout << tri[1][1];
	/*
	queue < pair<int, pair<int, int>>> q;
	dist[1][1] = 7;
	q.push({ tri[1][1], {1, 1} });

	while (!q.empty()) {
		int d = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();

		if (x >= n) {
			ans = max(ans, d);
			continue;
		}

		if (dist[x + 1][y] < d + tri[x + 1][y]) {
			dist[x + 1][y] = d + tri[x + 1][y];
			q.push({ dist[x + 1][y], {x + 1, y} });
		}
		if (dist[x + 1][y + 1] < d + tri[x + 1][y + 1]) {
			dist[x + 1][y + 1] = d + tri[x + 1][y + 1];
			q.push({ dist[x + 1][y + 1], {x + 1, y + 1} });
		}
	}

	cout << ans;
	*/
}