#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int cnt[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

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
		stack<int> stock_place;
		stack<int> empty_place;

		while (cnt[i] > 0) {
			pair<int, int> container = rail.front();
			rail.pop();

			if (container.first == i) {
				cnt[i]--;

				while (!stock_place.empty() && stock_place.top() < container.second) {
					int light_container = stock_place.top();
					stock_place.pop();

					ans += light_container;

					empty_place.push(light_container);
				}

				ans += container.second;
				stock_place.push(container.second);

				while (!empty_place.empty()) {
					int light_container = empty_place.top();
					empty_place.pop();

					ans += light_container;

					stock_place.push(light_container);
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