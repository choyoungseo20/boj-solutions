#include <iostream>

using namespace std;

bool visited[6][6];

int main() {
	char c;
	int r;
	bool possible = true;
	int first_x, first_y;
	int last_x, last_y;
	for (int i = 0; i < 36; i++) {
		cin >> c >> r;
		int x = r - 1; 
		int y = c - 'A';
		if (visited[x][y]) {
			possible = false;
		}
		else {
			visited[x][y] = true;
			if (i != 0) {
				if (!((abs(last_x - x) == 2 && abs(last_y - y) == 1) || (abs(last_x - x) == 1 && abs(last_y - y) == 2))) {
					possible = false;
				}
			}
			else {
				first_x = x;
				first_y = y;
			}
		}
		last_x = x;
		last_y = y;
	}

	if (!((abs(last_x - first_x) == 2 && abs(last_y - first_y) == 1) || (abs(last_x - first_x) == 1 && abs(last_y - first_y) == 2))) {
		possible = false;
	}
	
	if (possible) cout << "Valid";
	else cout << "Invalid";
}