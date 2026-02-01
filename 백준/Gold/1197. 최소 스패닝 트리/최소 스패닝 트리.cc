#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<pair<int, pair<int, int>>> graph;
int parent[10001];

int find_root(int n) {
	if (n == parent[n]) return n;

	int root = find_root(parent[n]);
	parent[n] = root;

	return root;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int v, e;
	cin >> v >> e;

	int a, b, c;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;

		if (a < b) graph.push_back({ c, {a, b} });
		if (a > b) graph.push_back({ c, {b, a} });
		
	}

	sort(graph.begin(), graph.end());

	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}
	
	int ans = 0;
	for (auto n : graph) {
		int r1 = find_root(n.second.first);
		int r2 = find_root(n.second.second);
		if (r1 != r2) {
			ans += n.first;

			if (r1 < r2) parent[r2] = r1;
			if (r1 > r2) parent[r1] = r2;
		}
	}

	cout << ans;
}