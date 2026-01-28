#include <iostream>
#include <vector>

using namespace std;

int a[101];
int b[101];

vector<int> dp[101][101];

void comp(int x1, int y1, int x2, int y2) {
	if (dp[x2][y2].size() == 0) return;

	bool stop = false;
	int i = 0, j = 0;
	int size1 = dp[x1][y1].size();
	int size2 = dp[x2][y2].size();
	while (i < size1 && j < size2) {
		if (dp[x1][y1][i] > dp[x2][y2][j]) {
			stop = true;
			break;
		}
		if (dp[x1][y1][i] < dp[x2][y2][j]) {
			dp[x1][y1] = dp[x2][y2];
			stop = true;
			break;
		}
		i++, j++;
	}

	if (!stop) {
		if (size1 < size2) dp[x1][y1] = dp[x2][y2];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i] == b[j]) {
				dp[i][j] = dp[i - 1][j - 1];

				while (dp[i][j].size() && dp[i][j][dp[i][j].size() - 1] < a[i]) {
					dp[i][j].pop_back();
				}
				dp[i][j].push_back(a[i]);

				comp(i, j, i - 1, j);
				comp(i, j, i, j - 1);
			}
			else {
				dp[i][j] = dp[i - 1][j];

				comp(i, j, i, j - 1);
			}
		}
	}

	int size = dp[n][m].size();

	cout << size << "\n";

	for (int i = 0; i < size; i++) {
		cout << dp[n][m][i] << " ";
	}
}