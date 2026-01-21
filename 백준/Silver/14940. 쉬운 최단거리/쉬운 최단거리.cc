#include <iostream>
#include <queue>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int ans[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	int sx, sy;
	int num;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> num;
			if (num == 2) {
				sx = i;
				sy = j;
			}
			else if (num == 1) {
				ans[i][j] = -1;
			}
		}
	}

	queue<pair<int, pair<int, int>>> q;
	q.push({ 0, {sx, sy} });

	while (!q.empty()) {
		int dist = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (ans[nx][ny] != -1) continue;
			ans[nx][ny] = dist + 1;
			q.push({ dist + 1, {nx, ny} });
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}