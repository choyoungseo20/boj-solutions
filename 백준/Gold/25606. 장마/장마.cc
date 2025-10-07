#include <iostream>

using namespace std;

int ans[2][100001];
int minus_box[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, Q;
	cin >> N >> M >> Q;

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;

		int next_idx = a / M + 1 + i;
		if (a % M == 0) next_idx--;

		if (next_idx <= N) {
			minus_box[next_idx]++;
			ans[0][next_idx] += (M - (a % M)) % M;
			ans[1][next_idx] -= (M - (a % M)) % M;
		}

		ans[0][i] += a + ans[0][i - 1] - cnt * M;
		ans[1][i] += cnt * M;

		cnt -= minus_box[i];
		cnt++;
	}

	for (int i = 0; i < Q; i++) {
		int c, t;
		cin >> c >> t;

		cout << ans[c - 1][t] << "\n";
	}
}