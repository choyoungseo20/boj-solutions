#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int cnt[32001];
vector<int> adj[32001];

void topology_sort() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!cnt[i]) q.push(i);
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << " ";

		for (auto nx : adj[x]) {
			cnt[nx]--;
			if (!cnt[nx]) q.push(nx);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		cnt[b]++;
	}

	topology_sort();
}