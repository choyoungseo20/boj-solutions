#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	long long ans = 0;
	int a, last_a, max_a;
	for (int i = 0; i < n; i++) {
		cin >> a;

		if (i == 0) {
			max_a = a;
		}
		else {
			if (last_a < a) {
				ans += a - last_a;
			}
			if (max_a < a) max_a = a;
		}

		last_a = a;
	}

	ans += max_a - last_a;
	cout << ans;
}