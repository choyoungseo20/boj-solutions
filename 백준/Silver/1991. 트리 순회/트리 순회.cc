#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

pair<int, int> adj[26];
string ans1, ans2, ans3;
string tmp;

void dfs1(int x) {
	if (x == -1) return;

	ans1.push_back(x + 'A');
	dfs1(adj[x].first);
	dfs1(adj[x].second);
}

void dfs2(int x) {
	if (x == -1) return;

	dfs2(adj[x].first);
	ans2.push_back(x + 'A');
	dfs2(adj[x].second);
}

void dfs3(int x) {
	if (x == -1) return;

	dfs3(adj[x].first);
	dfs3(adj[x].second);
	ans3.push_back(x + 'A');
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;

	char n, ln, rn;
	for (int i = 0; i < N; i++) {
		cin >> n >> ln >> rn;
		int int_n = n - 'A';
		int int_ln = -1, int_rn = -1;
		if (ln != '.') int_ln = ln - 'A';
		if (rn != '.') int_rn = rn - 'A';
		adj[int_n] = { int_ln, int_rn };
	}

	dfs1(0);
	cout << ans1 << "\n";

	dfs2(0);
	cout << ans2 << "\n";

	dfs3(0);
	cout << ans3 << "\n";
}