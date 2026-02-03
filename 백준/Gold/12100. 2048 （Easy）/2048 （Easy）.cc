#include <iostream>
#include <vector>

using namespace std;

int n;
int ans;

void rec(vector<vector<int>> v, int idx) {
	if (idx == 5) return;

	vector<vector<int>> map;

	map = v;
	for (int i = 0; i < n; i++) {
		int jump = 0;
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0) {
				jump++;
				continue;
			}
			int s = 1;
			while (j + s < n && map[i][j + s] == 0) s++;
			if (j + s < n && map[i][j] == map[i][j + s]) {
				map[i][j] *= 2;
				ans = max(ans, map[i][j]);
				map[i][j + s] = 0;
			}
			
			int tmp = map[i][j];
			map[i][j] = 0;
			map[i][j - jump] = tmp;
		}
	}
	rec(map, idx + 1);

	map = v;
	for (int i = 0; i < n; i++) {
		int jump = 0;
		for (int j = n - 1; j >= 0; j--) {
			if (map[i][j] == 0) {
				jump++;
				continue;
			}
			int s = 1;
			while (j - s >= 0 && map[i][j - s] == 0) s++;
			if (j - s >= 0 && map[i][j] == map[i][j - s]) {
				map[i][j] *= 2;
				ans = max(ans, map[i][j]);
				map[i][j - s] = 0;
			}

			int tmp = map[i][j];
			map[i][j] = 0;
			map[i][j + jump] = tmp;
		}
	}
	rec(map, idx + 1);
	
	map = v;
	for (int i = 0; i < n; i++) {
		int jump = 0;
		for (int j = 0; j < n; j++) {
			if (map[j][i] == 0) {
				jump++;
				continue;
			}
			int s = 1;
			while (j + s < n && map[j + s][i] == 0) s++;
			if (j + s < n && map[j][i] == map[j + s][i]) {
				map[j][i] *= 2;
				ans = max(ans, map[j][i]);
				map[j + s][i] = 0;
			}

			int tmp = map[j][i];
			map[j][i] = 0;
			map[j - jump][i] = tmp;
		}
	}
	rec(map, idx + 1);

	map = v;
	for (int i = 0; i < n; i++) {
		int jump = 0;
		for (int j = n - 1; j >= 0; j--) {
			if (map[j][i] == 0) {
				jump++;
				continue;
			}
			int s = 1;
			while (j - s >= 0 && map[j - s][i] == 0) s++;
			if (j - s >= 0 && map[j][i] == map[j - s][i]) {
				map[j][i] *= 2;
				ans = max(ans, map[j][i]);
				map[j - s][i] = 0;
			}

			int tmp = map[j][i];
			map[j][i] = 0;
			map[j + jump][i] = tmp;
		}
	}
	rec(map, idx + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	vector<vector<int>> map(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			ans = max(ans, map[i][j]);
		}
	}

	rec(map, 0);

	cout << ans;
}