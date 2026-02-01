#include <iostream>
#include <vector>

using namespace std;

char map[9][9];

bool check_sq(int i, int j, int k) {
	int i_m = i / 3;
	int j_m = j / 3;

	for (int x = 0 + 3 * i_m; x < 3 + 3 * i_m; x++) {
		for (int y = 0 + 3 * j_m; y < 3 + 3 * j_m; y++) {
			if (map[x][y] - '0' == k) {
				return false;
			}
		}
	}

	return true;
}

bool check_row(int j, int k) {
	for (int i = 0; i < 9; i++) {
		if (map[i][j] - '0' == k) {
			return false;
		}
	}

	return true;
}

bool check_column(int i, int k) {
	for (int j = 0; j < 9; j++) {
		if (map[i][j] - '0' == k) {
			return false;
		}
	}

	return true;
}

bool check(int i, int j, int k) {
	return check_sq(i, j, k) && check_row(j, k) && check_column(i, k);
}

bool rec(int x, int y) {
	for (int i = x; i < 9; i++) {
		for (int j = y; j < 9; j++) {
			if (map[i][j] == '0') {
				bool possible = false;
				for (int k = 1; k <= 9; k++) {
					if (check(i, j, k)) {
						map[i][j] = k + '0';
						possible = rec(0, 0);

						if (possible) return true;
					}
				}
				if (!possible) {
					map[i][j] = '0';
					return false;
				}
			}
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
		}
	}

	if (rec(0, 0)) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << map[i][j];
			}
			cout << "\n";
		}
	}
}