#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq[200000];
int ans[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		
		for (int j = 0; j < k; j++) {
			int a;
			cin >> a;

			pq[a].push(i);
		}
	}

	for (int i = 0; i < M; i++) {
		int b;
		cin >> b;
		if (!pq[b].empty()) {
			ans[pq[b].top()]++;
			pq[b].pop();
		}
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}
}