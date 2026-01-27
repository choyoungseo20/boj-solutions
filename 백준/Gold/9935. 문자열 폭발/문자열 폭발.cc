#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string str, boom;
	cin >> str >> boom;
	int str_size = str.size();
	int boom_size = boom.size();

	string ans = str;
	int idx = 0;
	for (int i = 0; i < str_size; i++, idx++) {
		ans[idx] = str[i];
		if (ans[idx] == boom[boom_size - 1]) {
			if (idx + 1 < boom_size) continue;

			bool is_boom = true;
			for (int j = 0; j < boom_size; j++) {
				if (ans[idx + 1 - boom_size + j] != boom[j]) {
					is_boom = false;
					break;
				}
			}

			if (is_boom) {
				idx -= boom_size;
			}
		}
	}

	if (idx == 0) cout << "FRULA" << "\n";
	else {
		cout << ans.substr(0, idx) << "\n";
	}
}