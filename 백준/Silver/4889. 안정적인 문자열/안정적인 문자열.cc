#include <iostream>
#include <string>

using namespace std;

int make_stable_string(string str) {
	int cnt = 0;
	int open_bracket_cnt = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '{') {
			open_bracket_cnt++;
		}
		else if (str[i] == '}') {
			if (open_bracket_cnt > 0) {
				open_bracket_cnt--;
			}
			else {
				cnt++;
				open_bracket_cnt++;
			}
		}
	}

	cnt += open_bracket_cnt / 2;

	return cnt;
}

int main() {
	int i = 1;
	while (1) {
		string data;
		cin >> data;

		if (data[0] == '-') break;

		int ans = make_stable_string(data);
		
		cout << i << ". " << ans << "\n";
		i++;
	}
}