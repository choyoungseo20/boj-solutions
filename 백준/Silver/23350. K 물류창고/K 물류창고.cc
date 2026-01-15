#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	queue<pair<int, int>> rail;
	priority_queue<int> pq;

	int P, W;
	for (int i = 0; i < N; i++) {
		cin >> P >> W;
		rail.push({ P, W });
		pq.push(P);
	}

	stack<pair<int, int>> stock_place;
	stack<pair<int, int>> empty_place;

	int ans = 0;

	while (!rail.empty()) {
		pair<int, int> container = rail.front();
		rail.pop();

		if (container.first == pq.top()) {
			pq.pop();

			while (!stock_place.empty() && stock_place.top().first == container.first && stock_place.top().second < container.second) {
				pair<int, int> light_container = stock_place.top();
				stock_place.pop();

				ans += light_container.second;

				empty_place.push(light_container);
			}

			ans += container.second;
			stock_place.push(container);

			while (!empty_place.empty()) {
				pair<int, int> light_container = empty_place.top();
				empty_place.pop();

				ans += light_container.second;

				stock_place.push(light_container);
			}
		}
		else {
			ans += container.second;
			rail.push(container);
		}
	}

	cout << ans;
}