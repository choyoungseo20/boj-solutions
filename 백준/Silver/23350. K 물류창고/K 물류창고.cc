#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int cnt[101];

int main() {
	int N, M;
	cin >> N >> M;

	queue<pair<int, int>> rail;

	int P, W;
	for (int i = 0; i < N; i++) {
		cin >> P >> W;
		rail.push({ P, W });
		cnt[P]++;
	}

	int ans = 0;

	for (int i = M; i > 0; i--) {
		vector<int> stock_place;
		vector<int> empty_place;

		while (cnt[i] > 0) {
			pair<int, int> container = rail.front();
			rail.pop();

			if (container.first == i) {
				cnt[i]--;

				while (!stock_place.empty() && stock_place.back() < container.second) {
					int light_container = stock_place.back();
					stock_place.pop_back();

					ans += light_container;

					empty_place.push_back(light_container);
				}

				ans += container.second;
				stock_place.push_back(container.second);

				while (!empty_place.empty()) {
					int light_container = empty_place.back();
					empty_place.pop_back();

					ans += light_container;

					stock_place.push_back(light_container);
				}
			}
			else {
				ans += container.second;
				rail.push(container);
			}
		}
	}

	cout << ans;
}