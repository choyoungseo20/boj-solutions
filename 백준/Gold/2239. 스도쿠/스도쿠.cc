#include <iostream>
#include <vector>

using namespace std;

char map[9][9];
bool visited[10][9][3];

bool check_sq(int i, int j, int k) {
	int i_m = i / 3;
	int j_m = j / 3;

	return !visited[k][i_m * 3 + j_m][0];
}

bool check_row(int j, int k) {

	return !visited[k][j][1];
}

bool check_column(int i, int k) {

	return !visited[k][i][2];
}

bool check(int i, int j, int k) {
	return check_sq(i, j, k) && check_row(j, k) && check_column(i, k);
}

bool rec() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (map[i][j] == '0') {
				bool possible = false;
				for (int k = 1; k <= 9; k++) {
					if (check(i, j, k)) {
						map[i][j] = k + '0';

						int i_m = i / 3;
						int j_m = j / 3;
						visited[map[i][j] - '0'][i_m * 3 + j_m][0] = true;
						visited[map[i][j] - '0'][j][1] = true;
						visited[map[i][j] - '0'][i][2] = true;

						possible = rec();

						if (possible) return true;
						else {
							visited[map[i][j] - '0'][i_m * 3 + j_m][0] = false;
							visited[map[i][j] - '0'][j][1] = false;
							visited[map[i][j] - '0'][i][2] = false;
							map[i][j] = '0';
						}
					}
				}
				if (!possible) {
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

			int i_m = i / 3;
			int j_m = j / 3;
			visited[map[i][j] - '0'][i_m * 3 + j_m][0] = true;
			visited[map[i][j] - '0'][j][1] = true;
			visited[map[i][j] - '0'][i][2] = true;
		}
	}

	if (rec()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << map[i][j];
			}
			cout << "\n";
		}
	}
}