#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int adj[100001];
int cnt[100001];

int topology_sort(int n) {
	queue<int> q;
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (!cnt[i]) {
			q.push(i);
			res++;
		}
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		
		cnt[adj[x]]--;
		if (!cnt[adj[x]]) {
			q.push(adj[x]);
			res++;
		}
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++) {
			adj[i] = 0;
			cnt[i] = 0;
		}

		int s_n;
		for (int i = 1; i <= n; i++) {
			cin >> s_n;

			adj[i] = s_n;
			cnt[s_n]++;
		}

		cout << topology_sort(n) << "\n";
	}
}