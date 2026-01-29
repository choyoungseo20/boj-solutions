#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v;
int cost[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int c, n;
	cin >> c >> n;

	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a, b });
	}

	int idx = 1;
	while (1) {
		for (int i = 0; i < v.size(); i++) {
			if (idx < v[i].first) continue;

			cost[idx] = max(cost[idx], cost[idx - v[i].first] + v[i].second);
		}

		if (cost[idx] >= c) {
			break;
		}
		idx++;
	}

	cout << idx;
}