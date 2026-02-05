#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> c_v[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> j;
	vector<int> c;

	j = vector<pair<int, int>>(n);
	c = vector<int>(k);
	int max_c = 0;
	
	for (int i = 0; i < n; i++) {
		cin >> j[i].second >> j[i].first;
	}

	for (int i = 0; i < k; i++) {
		cin >> c[i];
		if (c[i] >= 1000001) c[i] = 1000000;
		max_c = max(max_c, c[i]);
	}

	sort(j.begin(), j.end());
	sort(c.begin(), c.end());

	for (auto a : j) {
		int v = a.first;
		int m = a.second;

		if (m > max_c) continue;

		int idx = -1;

		int l = 0;
		int r = k - 1;

		int s_mid = (l + r) / 2;
		while (l <= r) {
			int mid = (l + r) / 2;

			if (m <= c[mid]) {
				idx = mid;
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}

		if (idx != -1) {
			c_v[c[idx]].push_back(v);
		}
	}

	long long ans = 0;
	priority_queue<pair<int, int>> pq;
	for (int i = 0; i < k; i++) {
		if (c_v[c[i]].size() > 0) {
			pq.push({ c_v[c[i]][c_v[c[i]].size() - 1], c[i] });
			c_v[c[i]].pop_back();
		}
		
		if (pq.empty()) continue;

		auto a = pq.top();
		pq.pop();

		ans += a.first;

		if (c_v[a.second].size() <= 0) continue;

		pq.push({ c_v[a.second][c_v[a.second].size() - 1], a.second });
		c_v[a.second].pop_back();
	}

	cout << ans;
}