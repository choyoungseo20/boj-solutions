#include <iostream>

using namespace std;

long long mod = 1000000007;

long long gcd(long long a, long long b) {
	long long n = b;

	while (n) {
		n = a % b;
		a = b;
		b = n;
	}

	return a;
}

/*
long long find_cnt(long long q1, long long q2, int r) {
	if (q1 == 1) return q2 + r;

	long long md = q2 % q1;

	long long tmp_n = find_cnt(mod, q1, r * -1);
	long long n = ((q1 * tmp_n - r) / md) % q1;

	return n;
}
*/

long long mod_pow(long long n, long long e) {
	long long res = 1;
	while (e) {
		if (e & 1) res = res * n % mod;
		n = n * n % mod;
		e >>= 1;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int m;
	cin >> m;

	long long n, s;
	long long ans = 0;
	for (int i = 0; i < m; i++) {
		cin >> n >> s;

		long long d = gcd(n, s);
		n /= d;
		s /= d;

		/*
		long long cnt = find_cnt(n, mod % n, 1);
		long long inverse_n = ((mod * cnt + 1) / n) % mod;
		*/

		long long inverse_n = mod_pow(n, mod - 2);

		ans += s * inverse_n % mod;
	}

	cout << ans % mod;
}