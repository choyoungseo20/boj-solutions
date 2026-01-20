#include <iostream>
#include <queue>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int n, m, k;
int x_1, y_1, x_2, y_2;
char map[1001][1001];
int d[1001][1001];
int ans = -1;

void bfs(int max_move) {
	queue<pair<int, pair<int, int>>> q;
	q.push({ 0, {x_1, y_1} });
	d[x_1][y_1] = 0;

	while (!q.empty()) {
		int dist = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			for (int j = 1; j <= max_move; j++) {
				int nx = x + j * dx[i];
				int ny = y + j * dy[i];
				if (nx > 0 && nx <= n && ny > 0 && ny <= m) {
					if (map[nx][ny] == '.') {
						if (d[nx][ny] > dist + 1) {
							if (nx == x_2 && ny == y_2) {
								ans = dist + 1;
								return;
							}
							q.push({ dist + 1, {nx, ny} });
							d[nx][ny] = dist + 1;
						}
						else if (d[nx][ny] < dist + 1) break;
					}
					else break;
				}
				else break;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			d[i][j] = 987654321;
		}
	}

	cin >> x_1 >> y_1 >> x_2 >> y_2;

	bfs(1);
	if (ans == -1 || k == 1) {
		cout << ans;
		return 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			d[i][j] = 987654321;
		}
	}
	bfs(k);

	cout << ans;
}