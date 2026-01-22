#include <iostream>

using namespace std;

int dx[4] = { 1, 0, -1 ,0 };
int dy[4] = { 0, 1, 0, -1 };

char map[21][21];
bool visited[26];

int n, m;
int ans;

void dfs(int x, int y, int idx) {
	ans = max(ans, idx);
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (visited[map[nx][ny] - 'A']) continue;
		visited[map[nx][ny] - 'A'] = true;
		dfs(nx, ny, idx + 1);
		visited[map[nx][ny] - 'A'] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	visited[map[0][0] - 'A'] = true;
	dfs(0, 0, 1);

	cout << ans;
}