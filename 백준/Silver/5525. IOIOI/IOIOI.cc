#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	
	int ans = 0;
	if (n >= 500000) {
		cout << ans;
		return 0;
	}

	string p = "IOI";
	for (int i = 1; i < n; i++) {
		p.push_back('O');
		p.push_back('I');
	}

	int l = 0;
	int r = 3 + 2 * (n - 1);
	bool find = false;
	while (r <= m) {
		if (!find) {
			bool possible = true;
			int i;
			for (i = l; i < r; i++) {
				if (s[i] != p[i - l]) { 
					possible = false;
					break; 
				}
			}
			if (possible) {
				find = true;
				ans++;
				l += 2;
				r += 2;
			}
			else {
				int jump = i - l;
				l += jump;
				r += jump;
				if (jump % 2 == 0) {
					l += 1;
					r += 1;
				}
			}
		}
		else {
			if (s[r - 2] == 'O' && s[r - 1] == 'I') {
				ans++;
				l += 2;
				r += 2;
			}
			else {
				find = false;
				int jump = r - l;
				if (s[r - 2] != s[r - 1]) {
					l -= 2;
					r -= 2;
				}
				else if (s[r - 2] == 'I' && s[r - 1] == 'I') {
					l -= 1;
					r -= 1;
				}
				l += jump;
				r += jump;
			}
		}
	}

	cout << ans;
}