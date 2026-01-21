#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int box[101][101][101];
bool visited[101][101][101];

struct Point {
	int x;
	int y;
	int z;
	int dist;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int m, n, h;
	cin >> m >> n >> h;

	vector<Point> v;
	bool all_ripe = true;
	for (int k = 1; k <= h; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> box[i][j][k];
				if (box[i][j][k] == 1) {
					v.push_back({ i, j, k, 0 });
				}
				else if (box[i][j][k] == 0) {
					all_ripe = false;
				}
			}
		}
	}

	if (all_ripe) {
		cout << 0;
		return 0;
	}

	queue<Point> q;
	for (int i = 0; i < v.size(); i++) {
		q.push(v[i]);
		visited[v[i].x][v[i].y][v[i].z] = true;
	}
	
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		int d = q.front().dist;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			int nd = d + 1;

			if (nx <= 0 || nx > n || ny <= 0 || ny > m || nz <= 0 || nz > h) continue;
			if (box[nx][ny][nz] == -1 || visited[nx][ny][nz]) continue;
			box[nx][ny][nz] = nd;
			visited[nx][ny][nz] = true;
			q.push({ nx, ny, nz, nd });
		}
	}

	int ans = 0;
	for (int k = 1; k <= h; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (box[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
				else {
					ans = max(ans, box[i][j][k]);
				}
			}
		}
	}

	cout << ans;
}