#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
	long long n = b;

	while (n) {
		n = a % b;
		a = b;
		b = n;
	}

	return a;
}

long long find_cnt(long long q1, long long q2, int r) {
	if (q1 == 1) return q2 + r;

	long long mod = q2 % q1;

	long long tmp_n = find_cnt(mod, q1, r * -1);
	long long n = ((q1 * tmp_n - r) / mod) % q1;

	return n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int m;
	cin >> m;

	long long mod = 1000000007;

	long long n, s;
	long long ans = 0;
	for (int i = 0; i < m; i++) {
		cin >> n >> s;

		long long d = gcd(n, s);
		n /= d;
		s /= d;

		long long cnt = find_cnt(n, mod % n, 1);
		long long inverse_n = ((mod * cnt + 1) / n) % mod;

		ans += (s * inverse_n) % mod;
	}

	cout << ans % mod;
}