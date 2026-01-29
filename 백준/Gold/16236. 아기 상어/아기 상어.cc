#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

int n;
int map[21][21];
bool visited[21][21];

int fish_cnt[7];

int ans = 0;
int shark_size = 2;
int eat = 0;

int cx, cy;
bool possible;

void bfs() {
	int total_fish_cnt = 0;
	for (int i = 1; i <= 6; i++) {
		if (i >= shark_size) break;

		total_fish_cnt += fish_cnt[i];
	}

	if (!total_fish_cnt) {
		possible = false;
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}

	queue<pair<pair<int, int>, int>> q;
	q.push({ {cx, cy}, 0 });
	visited[cx][cy] = true;
	map[cx][cy] = 0;

	possible = false;
	cx = 100, cy = 100;
	int max_d = 987654321;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int d = q.front().second;
		q.pop();

		if (max_d < d) break;

		if (map[x][y] != 0 && map[x][y] < shark_size) {
			possible = true;
			max_d = d;

			if (cx > x || (cx == x && cy > y)) {
				cx = x;
				cy = y;
			}
		}
		
		if (possible) continue;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (visited[nx][ny] || map[nx][ny] > shark_size) continue;

			visited[nx][ny] = true;
			q.push({ {nx, ny}, d + 1 });
		}
	}

	if (possible) {
		eat += 1;
		int tmp = eat;
		eat %= shark_size;
		shark_size += tmp / shark_size;

		ans += max_d;

		fish_cnt[map[cx][cy]]--;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				cx = i;
				cy = j;
			}
			else if (map[i][j]) {
				fish_cnt[map[i][j]]++;
			}
		}
	}

	possible = true;
	while (possible) {
		bfs();
	}

	cout << ans;
}