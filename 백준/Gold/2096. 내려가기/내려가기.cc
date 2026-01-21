#include <iostream>
#include <algorithm>

using namespace std;

int dp[100000][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> dp[i][j];
		}
	}

	int ans1[3];
	int ans2[3];
	for (int i = 0; i < 3; i++) {
		ans1[i] = ans2[i] = dp[n - 1][i];
	}
	for (int i = n - 2; i >= 0; i--) {
		int new_ans1[3];
		int new_ans2[3];
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				new_ans1[j] = max(ans1[j], ans1[j + 1]) + dp[i][j];
				new_ans2[j] = min(ans2[j], ans2[j + 1]) + dp[i][j];
			}
			else if (j == 1) {
				new_ans1[j] = max({ ans1[j - 1], ans1[j], ans1[j + 1] }) + dp[i][j];
				new_ans2[j] = min({ ans2[j - 1], ans2[j], ans2[j + 1] }) + dp[i][j];
			}
			else {
				new_ans1[j] = max(ans1[j - 1], ans1[j]) + dp[i][j];
				new_ans2[j] = min(ans2[j - 1], ans2[j]) + dp[i][j];
			}	
		}
		for (int j = 0; j < 3; j++) {
			ans1[j] = new_ans1[j];
			ans2[j] = new_ans2[j];
		}
	}

	cout << max({ ans1[0], ans1[1], ans1[2] }) << " " << min({ ans2[0], ans2[1], ans2[2] });
}