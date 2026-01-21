#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[100001];
int ans[100001];

void dfs(int parent) {
	for (int i = 0; i < adj[parent].size(); i++) {
		int nx = adj[parent][i];
		if (ans[nx]) continue;

		ans[nx] = parent;
		dfs(nx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;

	int u, v;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	ans[1] = 1;
	dfs(1);

	for (int i = 2; i <= n; i++) {
		cout << ans[i] << "\n";
	}
}