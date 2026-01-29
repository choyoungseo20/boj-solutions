#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int n, m;
char map[1001][1001];
int dist[1001][1001];
bool visited[1001][1001];

int ans;

void bfs1() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ { n, m }, 1 });
	dist[n][m] = 1;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int d = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
			if (dist[nx][ny] != INF || map[nx][ny] == '1') continue;

			q.push({ {nx, ny}, d + 1 });
			dist[nx][ny] = d + 1;
		}
	}
	ans = dist[1][1];
}

void bfs2() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ { 1, 1 }, 1 });
	visited[1][1] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int d = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
			if (visited[nx][ny]) continue;

			if (map[nx][ny] == '1') {
				for (int j = 0; j < 4; j++) {
					int nnx = nx + dx[j];
					int nny = ny + dy[j];

					if (nnx <= 0 || nnx > n || nny <= 0 || nny > m) continue;
					if (visited[nnx][nny] || map[nnx][nny] == '1') continue;

					ans = min(ans, d + 1 + dist[nnx][nny]);
				}
			}
			else {
				q.push({ {nx, ny}, d + 1 });
				visited[nx][ny] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			dist[i][j] = INF;
		}
	}

	bfs1();
	bfs2();

	if (ans == INF) cout << -1;
	else cout << ans;
}