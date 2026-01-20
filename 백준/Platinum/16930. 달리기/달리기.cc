#include <iostream>
#include <vector>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

char map[1001][1001];
int d[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	int x_1, y_1, x_2, y_2;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			d[i][j] = 987654321;
		}
	}

	cin >> x_1 >> y_1 >> x_2 >> y_2;

	int ans = -1;

	vector<pair<int, pair<int, int>>> q;
	q.reserve(1000000);
	q.push_back({ 0, {x_1, y_1} });
	d[x_1][y_1] = 0;
	int head = 0;

	while (head < q.size()) {
		int dist = q[head].first;
		int x = q[head].second.first;
		int y = q[head].second.second;
		head++;

		for (int i = 0; i < 4; i++) {
			for (int j = 1; j <= k; j++) {
				int nx = x + j * dx[i];
				int ny = y + j * dy[i];
				if (nx <= 0 || nx > n || ny <= 0 || ny > m) break;
				if (map[nx][ny] != '.') break;
				if (d[nx][ny] < dist + 1) break;
				if (d[nx][ny] > dist + 1) {
					if (nx == x_2 && ny == y_2) {
						ans = dist + 1;
						cout << ans;
						return 0;
					}
					q.push_back({ dist + 1, {nx, ny} });
					d[nx][ny] = dist + 1;
				}
			}
		}
	}

	cout << ans;
}