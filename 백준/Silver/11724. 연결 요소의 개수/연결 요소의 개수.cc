#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[1001];
bool visited[1001];

void dfs(int n) {
	for (int i = 0; i < adj[n].size(); i++) {
		if (visited[adj[n][i]]) continue;

		visited[adj[n][i]] = true;
		dfs(adj[n][i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;

		ans++;
		visited[i] = true;
		dfs(i);
	}

	cout << ans;
}