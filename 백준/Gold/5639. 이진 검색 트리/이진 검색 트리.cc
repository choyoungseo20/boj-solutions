#include <iostream>
#include <vector>

using namespace std;

int dx[4] = { 1, 0, -1 ,0 };
int dy[4] = { 0, 1, 0, -1 };

pair<int, int> adj[10001];
vector<int> v(10001);

int n;
int ans;

void dfs(int x) {
	if (x == 0) return;

	dfs(adj[x].first);
	dfs(adj[x].second);

	cout << v[x] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int node;
	while (cin >> node) {
		v[++n] = node;
	}

	int right = v[1];
	int right_idx = 1;
	for (int i = 2; i <= n; i++) {
		if (v[i - 1] > v[i]) {
			adj[i - 1].first = i;
		}
		else {
			if (right < v[i]) {
				adj[right_idx].second = i;
				right = v[i];
				right_idx = i;
				continue;
			}
			int left = v[i - 1];
			int left_idx = i - 1;
			for (int j = i - 1; j >= 2; j--) {
				if (left < v[i] && v[i] < v[j - 1]) {
					adj[left_idx].second = i;
					break;
				}
				if (left < v[j - 1]) {
					left = v[j - 1];
					left_idx = j - 1;
				}
			}
		}
	}

	dfs(1);
}