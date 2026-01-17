#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, t;
	cin >> n >> t;

	vector<int> a(n * 2);
	for (int i = 0; i < n * 2; i++) {
		cin >> a[i];
	}

	int b;
	int idx = 0;
	for (int i = 0; i < t; i++) {
		cin >> b;

		idx = (idx + b - 1) % (n * 2);
		cout << a[idx] << " ";
	}
}