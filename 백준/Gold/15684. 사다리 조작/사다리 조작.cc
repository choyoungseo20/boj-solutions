#include <iostream>

using namespace std;

// H x N
bool board[31][11];

int N, M, H;
int ans = 4;

void back_tracking(int idx, int r, int c) {
	bool possible = true;
	for (int start = 1; start <= N; start++) {
		int pos = start;
		for (int i = 1; i <= H; i++) {
			if (board[i][pos]) pos++;
			else if (board[i][pos - 1]) pos--;
		}
		if (pos != start) {
			possible = false;
			break;
		}
	}

	if (possible) {
		ans = min(ans, idx);
		return;
	}

	if (idx == 3 || idx >= ans) return;

	for (int i = r; i <= H; i++) {
		int k = 1;
		if (i == r) k = c;
		for (int j = k; j < N; j++) {
			if (!board[i][j] && !board[i][j + 1] && !board[i][j - 1]) {
				board[i][j] = true;
				back_tracking(idx + 1, i, j);
				board[i][j] = false;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> H;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		board[a][b] = true;
	}

	back_tracking(0, 1, 1);

	if (ans < 4) cout << ans;
	else cout << -1;	
}