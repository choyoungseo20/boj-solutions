#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;

	int open_bracket_cnt = 0;
	int ans = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			open_bracket_cnt++;
		}
		else if (str[i] == ')') {
			if (open_bracket_cnt > 0) {
				open_bracket_cnt--;
			}
			else {
				ans++;
			}
		}
	}

	ans += open_bracket_cnt;
	cout << ans;
}