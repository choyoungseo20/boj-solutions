#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

vector<pair<int, int>> c;
int map[101][101];
bool visited[101][101];

int n, m;

void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i, j });
	visited[i][j] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (visited[nx][ny] || map[nx][ny]) continue;

			visited[nx][ny] = true;
			q.push({ nx, ny });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j]) c.push_back({ i, j });
		}
	}

	bfs(0, 0);

	int t = 0;
	int cnt = c.size();
	while (cnt) {
		t++;

		vector<pair<int, int>> tmp;
		for (auto a : c) {
			if (visited[a.first][a.second]) continue;

			int ex = 0;
			for (int i = 0; i < 4; i++) {
				int nx = a.first + dx[i];
				int ny = a.second + dy[i];

				if (visited[nx][ny]) ex++;
			}

			if (ex >= 2) {
				tmp.push_back(a);
			}
		}

		for (auto a : tmp) {
			bfs(a.first, a.second);
			cnt--;
		}
	}

	cout << t;
}