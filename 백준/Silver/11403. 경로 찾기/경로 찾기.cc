#include <iostream>
#include <vector>
#include <string>

using namespace std;

int ans[101][101];
vector<int> v[101];

void dfs(int s, int c) {
	for (int i = 0; i < v[c].size(); i++) {
		if (ans[s][v[c][i]]) continue;
		ans[s][v[c][i]] = 1;
		dfs(s, v[c][i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int e;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> e;
			if (e == 1) v[i].push_back(j);
		}
	}
	
	for (int i = 0; i < n; i++) {
		dfs(i, i);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}