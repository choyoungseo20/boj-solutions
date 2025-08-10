#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> adj[100001];
bool visited[100001];

int max_dist_n = 1;
int max_dist = 0;

void dfs(int n, int dist) {
	for (int i = 0; i < adj[n].size(); i++) {	
		if (!visited[adj[n][i].first]) {
			if (max_dist < dist + adj[n][i].second) {
				max_dist_n = adj[n][i].first;
				max_dist = dist + adj[n][i].second;
			}

			visited[adj[n][i].first] = true;
			dfs(adj[n][i].first, dist + adj[n][i].second);
		}		
	}
}

int main() {
	int V;
	cin >> V;

	int n, nn, d;
	for (int i = 0; i < V; i++) {
		cin >> n;
		while (1) {
			cin >> nn;
			if (nn == -1) break;
			cin >> d;
			
			adj[n].push_back({nn, d});
		}
	}

	visited[max_dist_n] = true;
	dfs(max_dist_n, 0);

	fill(visited, visited + V + 1, false);
	visited[max_dist_n] = true;
	dfs(max_dist_n, 0);

	cout << max_dist;
}