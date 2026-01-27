#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int bomb_idx_cnt[37]; // 폭발 문자열 인덱스별 필요 개수
int last_idx[62];

vector<pair<int, int>> next_info[63];

int bomb_char_cnt[62];
int char_cnt[62];

bool visited[1000000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string str, bomb;
	cin >> str >> bomb;
	int str_size = str.size();
	int bomb_size = bomb.size();

	int s_c, l_c;
	for (int i = 0; i < bomb_size; i++) {
		int c;

		if (bomb[i] >= '0' && bomb[i] <= '9') c = bomb[i] - '0';
		if (bomb[i] >= 'a' && bomb[i] <= 'z') c = bomb[i] - 'a' + 10;
		if (bomb[i] >= 'A' && bomb[i] <= 'Z') c = bomb[i] - 'A' + 10 + 26;

		if (i == 0) {
			s_c = c;
			l_c = c;
		}
		else {
			next_info[l_c].push_back({ c, i });
			l_c = c;
		}

		if (last_idx[c] > 0) {
			bomb_idx_cnt[i] = bomb_idx_cnt[last_idx[c] - 1] + 1;
		}
		else {
			bomb_idx_cnt[i] = 1;
		}

		last_idx[c] = i + 1;
		bomb_char_cnt[c]++;
	}

	bool is_bomb = false;
	int visited_size = 0;
	int c_c = 62;
	vector<int> tmp_bomb_idx;
	for (int i = 0; i < str_size; i++) {
		int str_c, bomb_c;

		if (str[i] >= '0' && str[i] <= '9') str_c = str[i] - '0';
		if (str[i] >= 'a' && str[i] <= 'z') str_c = str[i] - 'a' + 10;
		if (str[i] >= 'A' && str[i] <= 'Z') str_c = str[i] - 'A' + 10 + 26;

		if (!is_bomb) {
			if (str[i] == bomb[0]) {
				if (bomb_size == 1) {
					visited[i] = true;
					visited_size++;
					continue;
				}

				tmp_bomb_idx.push_back(i);
				char_cnt[str_c]++;
				is_bomb = true;
				c_c = str_c;
			}
		}
		else {
			tmp_bomb_idx.push_back(i);

			int k = -1;
			// 잘 생각해보고 고치자
			// abac
			// abc
			// a -> 틀림
			if (str_c == s_c) {
				k = 0;
			}
			for (int j = 0; j < next_info[c_c].size(); j++) {
				auto ni = next_info[c_c][j];
				if (str_c == ni.first) {

					if (bomb[ni.second - 1] >= '0' && bomb[ni.second - 1] <= '9') bomb_c = bomb[ni.second - 1] - '0';
					if (bomb[ni.second - 1] >= 'a' && bomb[ni.second - 1] <= 'z') bomb_c = bomb[ni.second - 1] - 'a' + 10;
					if (bomb[ni.second - 1] >= 'A' && bomb[ni.second - 1] <= 'Z') bomb_c = bomb[ni.second - 1] - 'A' + 10 + 26;

					if (char_cnt[bomb_c] >= bomb_idx_cnt[ni.second - 1]) {
						k = ni.second;
					}
					else {
						break;
					}
				}
				
			}
			if (k != -1) {
				char_cnt[str_c]++;
				c_c = str_c;
			}
			if (k == bomb_size - 1) {
				for (int j = 0; j < 62; j++) {
					char_cnt[j] -= bomb_char_cnt[j];
				}
				for (int j = 0; j < bomb_size; j++) {
					visited[tmp_bomb_idx[tmp_bomb_idx.size() - 1]] = true;
					visited_size++;
					tmp_bomb_idx.pop_back();
				}
				if (tmp_bomb_idx.size() != 0) {
					char tmp = str[tmp_bomb_idx[tmp_bomb_idx.size() - 1]];

					if (tmp >= '0' && tmp <= '9') c_c = tmp - '0';
					if (tmp >= 'a' && tmp <= 'z') c_c = tmp - 'a' + 10;
					if (tmp >= 'A' && tmp <= 'Z') c_c = tmp - 'A' + 10 + 26;

				}
				else {
					is_bomb = false;
					c_c = 62;
				}
			}
			if (k == -1) {
				for (int j = 0; j < 62; j++) {
					char_cnt[j] = 0;
				}
				tmp_bomb_idx = vector<int>();
				is_bomb = false;
				c_c = 62;
			}
		}
	}

	if (visited_size == str_size) {
		cout << "FRULA";
	}
	else {
		for (int i = 0; i < str_size; i++) {
			if (!visited[i]) cout << str[i];
		}
	}
}