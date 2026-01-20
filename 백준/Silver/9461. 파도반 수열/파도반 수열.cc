#include <iostream>

using namespace std;

long long a[101];

int main() {
	a[1] = 1;
	a[2] = 1;
	a[3] = 1;
	a[4] = 2;
	a[5] = 2;
	for (int i = 6; i <= 100; i++) {
		a[i] = a[i - 1] + a[i - 5];
	}

	int t, n;
	cin >> t;
	
	while (t--) {
		cin >> n;
		cout << a[n] << "\n";
	}
}