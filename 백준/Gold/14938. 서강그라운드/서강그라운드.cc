#include <iostream>

using namespace std;

int item[101];
int dp[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, r;
	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++) {
		cin >> item[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) dp[i][j] = 987654321;
		}
	}

	int a, b, l;
	for (int i = 0; i < r; i++) {
		cin >> a >> b >> l;
		dp[a][b] = l;
		dp[b][a] = l;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] <= m) sum += item[j];
		}
		ans = max(ans, sum);
	}

	cout << ans;
}