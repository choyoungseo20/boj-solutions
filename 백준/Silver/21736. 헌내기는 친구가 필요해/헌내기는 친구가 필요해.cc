#include <iostream>
#include <queue>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

char cp[601][601];
bool visited[601][601];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	int sx, sy;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> cp[i][j];
			if (cp[i][j] == 'I') {
				sx = i;
				sy = j;
			}
		}
	}

	int ans = 0;

	queue<pair<int, int>> q;
	q.push({ sx, sy });
	visited[sx][sy] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (cp[nx][ny] == 'X' || visited[nx][ny]) continue;
			if (cp[nx][ny] == 'P') ans++;

			visited[nx][ny] = true;
			q.push({ nx, ny });
		}
	}


	if (ans == 0) cout << "TT";
	else cout << ans;
}