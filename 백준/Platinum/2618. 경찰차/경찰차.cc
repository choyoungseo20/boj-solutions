#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dp[1002][1002];
int dist_sum[1002];
pair<int, int> parent[1002][1002];
int last_copy[1002][1002];
int idx_copy[1002][1002];
vector<pair<int, int>> pos;

string back_tracking(int r, int c) {
	if (c == 0) {
		if (r == 1) return "1";
		else return "2";
	}

	string res = back_tracking(parent[r][c].first, parent[r][c].second);

	char last_num = res[res.size() - 1];
	for (int i = 0; i < last_copy[r][c]; i++) {
		res.push_back(last_num);
	}

	if (idx_copy[r][c] != 0) {
		char idx_num = res[abs(idx_copy[r][c]) - 1];

		if (idx_copy[r][c] < 0) {
			if (idx_num == '1') res.push_back('2');
			else res.push_back('1');
		}
		else res.push_back(idx_num);
	}

	return res; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, w;
	cin >> n >> w;

	int r, c;
	for (int i = 0; i < w; i++) {
		cin >> r >> c;
		
		dp[0][i + 2] = 987654321;
		dp[1][i + 2] = abs(1 - r) + abs(1 - c);
		dp[2][i + 2] = abs(n - r) + abs(n - c);
		for (int j = 0; j < pos.size(); j++) {
			dp[j + 3][i + 2] = abs(pos[j].first - r) + abs(pos[j].second - c);
		}

		pos.push_back({ r, c });
	}

	for (int i = 3; i < w + 2; i++) {
		dist_sum[i] = dp[i][i] + dist_sum[i - 1];
	}

	int car1_first_move = dp[1][2];
	parent[1][1] = { 1, 0 };
	parent[1][2] = { 1, 1 };
	int car2_first_move = dp[2][2];
	parent[2][1] = { 2, 0 };
	parent[2][2] = { 2, 1 };

	if (dp[2][2] > dp[1][2]) {
		dp[2][2] = dp[1][2];
		parent[2][2] = parent[1][2];
	}
	for (int i = 3; i < w + 2; i++) {
		for (int j = 1; j < w + 2; j++) {
			if (j > i) break;

			if (j == 1) {
				dp[j][i] += dist_sum[i - 1] + car2_first_move;
				parent[j][i] = parent[2][1];
				last_copy[j][i] = i - 3;
				idx_copy[j][i] = -1;
			}
			else if (j == 2) {
				dp[j][i] += dist_sum[i - 1] + car1_first_move;
				parent[j][i] = parent[1][1];
				last_copy[j][i] = i - 3;
				idx_copy[j][i] = -1;
			}
			else if (j == i) {
				dp[j][i] += dp[j - 1][i - 1];
				parent[j][i] = { j - 1, i - 1 };
				last_copy[j][i] = 1;
			}
			else {
				dp[j][i] += dp[j - 1][j] + dist_sum[i - 1] - dist_sum[j];
				parent[j][i] = { j - 1, j };
				last_copy[j][i] = i - j - 1;
				idx_copy[j][i] = j - 2;
			}

			if (dp[j][i] > dp[j - 1][i]) {
				dp[j][i] = dp[j - 1][i];
				parent[j][i] = parent[j - 1][i];
				last_copy[j][i] = last_copy[j - 1][i];
				idx_copy[j][i] = idx_copy[j - 1][i];
			}
		}
	}

	string tracking_res = back_tracking(w + 1, w + 1);


	/*
	for (int i = 1; i <= w + 1; i++) {
		for (int j = 1; j <= w + 1; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	*/

	cout << dp[w + 1][w + 1] << "\n";
	for (int i = 0; i < tracking_res.size(); i++) {
		cout << tracking_res[i] << "\n";
	}
}