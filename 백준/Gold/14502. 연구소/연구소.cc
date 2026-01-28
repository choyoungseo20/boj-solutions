#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int map[9][9];
bool visited[9][9];

int n, m;
int safe_area;
int ans;

vector<pair<int, int>> v;

void bfs() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}

	queue<pair<int, int>> q;
	for (auto a : v) {
		q.push(a);
		visited[a.first][a.second] = true;
	}

	int res = safe_area - 3;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (visited[nx][ny] || map[nx][ny]) continue;
			
			res--;
			visited[nx][ny] = true;
			q.push({ nx, ny });
		}
	}
	
	ans = max(res, ans);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) safe_area++;
			if (map[i][j] == 2) {
				v.push_back({ i, j });
			}
		}
	}

	for (int w1 = 0; w1 < n * m; w1++) {
		int x1 = w1 / m, y1 = w1 % m;
		if (map[x1][y1] != 0) continue;

		map[x1][y1] = 1;
		for (int w2 = w1 + 1; w2 < n * m; w2++) {
			int x2 = w2 / m, y2 = w2 % m;
			if (map[x2][y2] != 0) continue;

			map[x2][y2] = 1;
			for (int w3 = w2 + 1; w3 < n * m; w3++) {
				int x3 = w3 / m, y3 = w3 % m;
				if (map[x3][y3] != 0) continue;
				map[x3][y3] = 1;

				bfs();

				map[x3][y3] = 0;
			}
			map[x2][y2] = 0;
		}
		map[x1][y1] = 0;
	}

	cout << ans;
}