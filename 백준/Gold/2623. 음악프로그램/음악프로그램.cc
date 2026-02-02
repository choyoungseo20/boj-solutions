#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[1001];
vector<int> ans;
int cnt[1001];
int visited;
int n, m;

void topology_sort() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!cnt[i]) {
			q.push(i);
			ans.push_back(i);
			visited++;
		}
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (auto nx : adj[x]) {
			cnt[nx]--;
			if (cnt[nx] == 0) {
				q.push(nx);
				ans.push_back(nx);
				visited++;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	int s_n;
	for (int i = 0; i < m; i++) {
		cin >> s_n;
		vector<int> s(s_n);
		for (int j = 0; j < s_n; j++) {
			cin >> s[j];
			if (j == 0) continue;

			adj[s[j - 1]].push_back(s[j]);
			cnt[s[j]]++;
		}
	}

	topology_sort();

	if (visited != n) cout << 0;
	else {
		for (auto a : ans) cout << a << "\n";
	}
}