#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int, int>> adj[10001];
bool visited[10001];

int idx;
int max_sum;
void dfs(int x, int sum) {
	bool is_leaf = true;
	for (int i = 0; i < adj[x].size(); i++) {
		if (visited[adj[x][i].first]) continue;
		is_leaf = false;
		visited[adj[x][i].first] = true;
		dfs(adj[x][i].first, sum + adj[x][i].second);
	}

	if (is_leaf) {
		if (sum > max_sum) {
			idx = x;
			max_sum = sum;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;

	int u, v, c;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v >> c;
		adj[u].push_back({ v, c });
		adj[v].push_back({ u, c });
	}

	visited[1] = true;
	dfs(1, 0);

	memset(visited, false, sizeof(visited));

	visited[idx] = true;
	dfs(idx, 0);

	cout << max_sum;
}