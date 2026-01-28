#include <iostream>

using namespace std;

long long ex_gcd(long long a, long long b) {
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

	long long md = q2 % q1;

	long long tmp_n = find_cnt(md, q1, r * -1);
	long long n = ((q1 * tmp_n - r) / md) % q1;

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

		long long gcd = ex_gcd(n, s);
		n /= gcd;
		s /= gcd;

		long long cnt = find_cnt(n, mod % n, 1);
		long long inverse_n = ((mod * cnt + 1) / n) % mod;

		ans += (s * inverse_n) % mod;
	}

	cout << ans % mod;
}