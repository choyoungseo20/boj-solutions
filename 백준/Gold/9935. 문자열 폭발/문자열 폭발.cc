#include <iostream>
#include <string>
#include <vector>

using namespace std;

int bomb_idx_cnt[37]; // 폭발 문자열 인덱스별 필요 개수

vector<pair<int, int>> next_info[63];

int bomb_char_cnt[62];
int char_cnt[62];

bool visited[1000000];

int ctoi(char c) {
	if (c >= '0' && c <= '9') return c - '0';
	if (c >= 'a' && c <= 'z') return c - 'a' + 10;
	if (c >= 'A' && c <= 'Z') return c - 'A' + 10 + 26;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string str, bomb;
	cin >> str >> bomb;
	int str_size = str.size();
	int bomb_size = bomb.size();

	int s_c, l_c;
	for (int i = 0; i < bomb_size; i++) {
		int c = ctoi(bomb[i]);

		if (i == 0) {
			s_c = c;
			l_c = c;
		}
		else {
			next_info[l_c].push_back({ c, i });
			l_c = c;
		}

		bomb_char_cnt[c]++;
		bomb_idx_cnt[i] = bomb_char_cnt[c];
	}

	bool is_bomb = false;
	int visited_size = 0;
	int c_c = 62;
	vector<int> tmp_bomb_idx;
	for (int i = 0; i < str_size; i++) {
		int str_c = ctoi(str[i]);

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
			int k = -1;
			if (str_c == s_c) {
				k = 0;
			}
			for (int j = 0; j < next_info[c_c].size(); j++) {
				auto ni = next_info[c_c][j];
				if (str_c == ni.first) {
					int bomb_c = ctoi(bomb[ni.second - 1]);

					if (char_cnt[bomb_c] >= bomb_idx_cnt[ni.second - 1]) {
						k = ni.second;
					}
					else break;
				}
			}

			tmp_bomb_idx.push_back(i);
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

					c_c = ctoi(tmp);
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