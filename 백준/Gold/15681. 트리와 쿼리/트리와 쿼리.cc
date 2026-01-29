#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[100001];
bool visited[100001];
int cnt[100001];

int dfs(int u) {
	int res = 1;

	for (auto v : tree[u]) {
		if (visited[v]) continue;

		visited[v] = true;
		res += dfs(v);
	}

	cnt[u] = res;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, r, q;
	cin >> n >> r >> q;

	int u, v;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	visited[r] = true;
	int find_ans = dfs(r);

	int node;
	for (int i = 0; i < q; i++) {
		cin >> node;
		cout << cnt[node] << "\n";
	}
}