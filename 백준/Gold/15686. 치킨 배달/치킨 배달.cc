#include <iostream>
#include <vector>

using namespace std;

int map[50][50];
int N, M;
int ans = 987654321;
vector<pair<int, int>> house;
vector<pair<bool, pair<int, int>>> chicken;
int chicken_cnt = 0;

void back_tracking(int idx, int chicken_idx) {
	int dist_sum = 0;
	for (int i = 0; i < house.size(); i++) {
		int dist = 987654321;
		for (int j = 0; j < chicken.size(); j++) {
			if (chicken[j].first) {
				dist = min(dist, abs(chicken[j].second.first - house[i].first) + abs(chicken[j].second.second - house[i].second));
			}
		}
		dist_sum += dist;
	}

	if (chicken_cnt - idx <= M || dist_sum >= ans) {
		ans = min(ans, dist_sum);
		return;
	}

	for (int i = chicken_idx; i < chicken.size(); i++) {
		if (chicken[i].first) {
			chicken[i].first = false;

			back_tracking(idx + 1, i + 1);

			chicken[i].first = true;
		}
	}

}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];

			if (map[i][j] == 1) house.push_back({ i, j });
			if (map[i][j] == 2) {
				chicken_cnt++;
				chicken.push_back({ true, { i, j } });
			}
		}
	}

	back_tracking(0, 0);

	cout << ans;
}