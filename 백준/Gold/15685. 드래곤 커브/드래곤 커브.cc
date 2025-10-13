#include <iostream>
#include <vector>

using namespace std;

int map[101][101];

int main() {	
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, -1, 0, 1 };

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;

		vector<pair<int, int>> v;
		v.push_back({ y, x });
		v.push_back({ y + dy[d], x + dx[d] });

		// 시뮬레이션
		// 드래곤 커브 생성
		for (int i = 0; i < g; i++) {
			int size = v.size();

			for (int j = size - 2; j >= 0; j--) {
				int n_x = v[size - 1].second + (v[size - 1].first - v[j].first);
				int n_y = v[size - 1].first - (v[size - 1].second - v[j].second);

				v.push_back({ n_y, n_x });
			}
		}

		for (int i = 0; i < v.size(); i++) {
			map[v[i].first][v[i].second]++;
		}
	}

	

	int ans = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] > 0 && map[i][j + 1] > 0 && map[i + 1][j] > 0 && map[i + 1][j + 1] > 0) {
				ans++;
			}
		}
	}

	cout << ans;
}