#include <iostream>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int n;
bool visited[101][101][2];
char map[101][101][2];

void dfs(int x, int y, int s) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (map[x][y][s] != map[nx][ny][s] || visited[nx][ny][s]) continue;
		visited[nx][ny][s] = true;
		dfs(nx, ny, s);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j][0];
			if (map[i][j][0] == 'G') map[i][j][1] = 'R';
			else map[i][j][1] = map[i][j][0];
		}
	}

	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j][0]) {
				visited[i][j][0] = true;
				ans1++;
				dfs(i, j, 0);
			}
			if (!visited[i][j][1]) {
				visited[i][j][1] = true;
				ans2++;
				dfs(i, j, 1);
			}
		}
	}

	cout << ans1 << " " << ans2;
}