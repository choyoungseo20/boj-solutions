#include <iostream>

using namespace std;

int dx[3] = { 0, 1, 1 };
int dy[3] = { 1, 1, 0 };

int n;
int map[17][17];
int ans;

void dfs(int x, int y, int state) { // state 0: 가로, state 1: 대각선, state 2: 세로
	if (x == n && y == n) {
		ans++;
		return;
	}

	int s = 0;
	int e = 3;
	if (state == 0) e = 2;
	if (state == 2) s = 1;
	for (int i = s; i < e; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx > n || ny > n) continue;
		if (map[nx][ny]) continue;
		if (i == 1 && (map[nx - 1][ny] || map[nx][ny - 1])) continue;
		dfs(nx, ny, i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	dfs(1, 2, 0);

	cout << ans;
}