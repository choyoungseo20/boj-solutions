#include <iostream>
#include <cmath>

using namespace std;

int iter(int idx, int r, int c) {
	if (idx == 0) return 0;

	int res = 0;
	int num = pow(2, (idx - 1) * 2);
	int area;
	int size = pow(2, idx);
	if (size / 2 > r && size / 2 > c) {
		area = 0;
	}
	else if (size / 2 > r && size / 2 <= c) {
		area = 1;
		c -= size / 2;
	}
	else if (size / 2 <= r && size / 2 > c) {
		area = 2;
		r -= size / 2;
	}
	else if (size / 2 <= r && size / 2 <= c) {
		area = 3;
		r -= size / 2;
		c -= size / 2;
	}
	res = area * num;
	res += iter(idx - 1, r, c);

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, r, c;
	cin >> n >> r >> c;

	cout << iter(n, r, c);
}