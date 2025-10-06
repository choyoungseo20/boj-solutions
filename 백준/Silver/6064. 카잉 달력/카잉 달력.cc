#include <iostream>

using namespace std;

// 최대공약수
int gcd(int a, int b) {
	int n;
	while (b != 0) {
		n = a % b;
		a = b;
		b = n;
	}
	return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int T;
	cin >> T;

	while (T--) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;

		int lcm = M * N / gcd(M, N); // 최소공배수

		int ans = -1;
		while (1) {
			if (x > lcm || y > lcm) break;
			if (x == y) {
				ans = x;
				break;
			}
			else if (x < y) {
				x += M;
			}
			else {
				y += N;
			}

		}

		cout << ans << "\n";
	}
}