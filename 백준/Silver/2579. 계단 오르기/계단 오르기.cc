#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;
vector<pair<int, int>> dp;

void back_tracking(int idx, int score, int jump) {
	if (idx > n) return;
	if (dp[idx].first >= score + v[idx] && dp[idx].second <= jump) return;
	if (dp[idx].first == score + v[idx]) dp[idx].second == 1;
	dp[idx].first = max(dp[idx].first, score + v[idx]);
	score += v[idx];

	if (jump < 2) {
		back_tracking(idx + 1, score, jump + 1);
	}
	back_tracking(idx + 2, score, 1);
}

int main() {
	cin >> n;

	v = vector<int>(n + 1, 0);
	dp = vector<pair<int, int>>(n + 1, { 0, 2 });
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	back_tracking(0, 0, 0);

	cout << dp[n].first;
}