#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> d;
vector<int> dp;
vector<int> cnt;
vector<int> adj[1001];

void topology_sort() {
	queue<int> q;

	for (int i = 1; i < cnt.size(); i++) {
		if (cnt[i] == 0) {
			q.push(i);
			dp[i] = d[i];
		}
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (auto nx : adj[x]) {
			cnt[nx]--;
			dp[nx] = max(dp[nx], dp[x] + d[nx]);
			if (cnt[nx] == 0) {
				q.push(nx);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		d = vector<int>(n + 1);
		dp = vector<int>(n + 1);
		cnt = vector<int>(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> d[i];

			adj[i].clear();
		}

		int x, y;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			adj[x].push_back(y);
			cnt[y]++;
		}

		int w;
		cin >> w;

		topology_sort();

		cout << dp[w] << "\n";
	}
}