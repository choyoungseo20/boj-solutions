#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[51];
vector<int> party[51];
bool visited[51];

void dfs(int x) {
	for (int i = 0; i < adj[x].size(); i++) {
		if (visited[adj[x][i]]) continue;
		visited[adj[x][i]] = true;
		dfs(adj[x][i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;

	int num;
	cin >> num;
	vector<int> v(num);
	for (int i = 0; i < num; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> num;
		
		int u;
		for (int j = 0; j < num; j++) {
			cin >> u;
			party[i].push_back(u);

			for (int k = 0; k < j; k++) {
				adj[u].push_back(party[i][k]);
				adj[party[i][k]].push_back(u);
			}
		}
	}

	for (int i = 0; i < v.size(); i++) {
		if (visited[v[i]]) continue;
		visited[v[i]] = true;
		dfs(v[i]);
	}

	int ans = 0;
	for (int i = 0; i < m; i++) {
		bool possible = true;

		for (int j = 0; j < party[i].size(); j++) {
			if (visited[party[i][j]]) {
				possible = false;
				break;
			}
		}

		if (possible) ans++;
	}
	cout << ans;
}