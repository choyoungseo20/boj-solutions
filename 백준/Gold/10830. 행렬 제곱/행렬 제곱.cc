#include <iostream>

using namespace std;

int mul[5][5][40];
int ans[5][5];
int tmp[5][5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	long long b;
	cin >> n >> b;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mul[i][j][1];
			if (i == j) ans[i][j] = 1;
		}
	}

	int idx = 1;
	long long p = 1;
	while (b >= p) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					mul[i][j][idx + 1] += mul[i][k][idx] * mul[k][j][idx];
					mul[i][j][idx + 1] %= 1000;
				}
			}
		}
		p *= 2;
		idx++;
	}

	while (b) {
		while (b < p) {
			p /= 2;
			idx--;
		}

		b -= p;

		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					tmp[i][j] += ans[i][k] * mul[k][j][idx];
					tmp[i][j] %= 1000;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ans[i][j] = tmp[i][j];
				tmp[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}