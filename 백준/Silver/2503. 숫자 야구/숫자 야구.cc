#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	string q;
	int s, b;
	vector<pair<string, pair<int, int>>> v;
	for (int i = 0; i < N; i++) {
		cin >> q >> s >> b;
		v.push_back({ q, { s, b } });
	}

	int ans = 0;
	for (int num = 100; num < 1000; num++) {
		string str_num = to_string(num);
		if (str_num[0] == str_num[1] || str_num[0] == str_num[2] || str_num[1] == str_num[2]) continue;
		if (str_num[0] == '0' || str_num[1] == '0' || str_num[2] == '0') continue;

		bool possible = true;
		for (int i = 0; i < N; i++) {
			q = v[i].first;
			int sans = v[i].second.first;
			int bans = v[i].second.second;
			int scnt = 0; 
			int bcnt = 0;
			for (int j = 0; j < 3; j++) {
				if (q[j] == str_num[j]) scnt++;
				if (q[j] == str_num[(j + 1) % 3] || q[j] == str_num[(j + 2) % 3]) bcnt++;
			}

			if (sans != scnt || bans != bcnt) {
				possible = false;
				break;
			}
		}
		if (possible) {
			ans++;
		}
	}

	cout << ans;
}