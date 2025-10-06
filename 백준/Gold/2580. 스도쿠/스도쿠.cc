#include <iostream>
#include <vector>

using namespace std;

int board[9][9];
vector<pair<int, int>> v;

bool back_tracking(int idx) {
	if (v.size() == idx) return true;

	int i = v[idx].first;
	int j = v[idx].second;
	int area_i = i / 3 * 3;
	int area_j = j / 3 * 3;
	for (int num = 1; num <= 9; num++) {
		bool possible = true;
		for (int k = 1; k <= 9; k++) {
			if (board[(i + k) % 9][j] == num) possible = false;
			if (board[i][(j + k) % 9] == num) possible = false;
		}
		for (int r = area_i; r < area_i + 3; r++) {
			for (int c = area_j; c < area_j + 3; c++) {
				if (board[r][c] == num) possible = false;
			}
		}

		if (possible) {
			board[i][j] = num;
			if (back_tracking(idx + 1)) return true;
			board[i][j] = 0;
		}
	}
	
	return false;
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) {
				v.push_back({ i, j });
			}
		}
	}

	if (back_tracking(0)) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j] << " ";
			}
			cout << "\n";
		}
	}
}