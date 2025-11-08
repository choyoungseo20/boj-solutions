#include <iostream>
#include <string>
using namespace std;

int main() {
	for (int i = 0; i < 3; i++) {
		string start_time;
		string end_time;
		cin >> start_time >> end_time;

		int h1 = stoi(start_time.substr(0, 2));
		int m1 = stoi(start_time.substr(3, 2));
		int s1 = stoi(start_time.substr(6, 2));
		int h2 = stoi(end_time.substr(0, 2));
		int m2 = stoi(end_time.substr(3, 2));
		int s2 = stoi(end_time.substr(6, 2));

		int ans = 0;

		while (1) {
			if (s1 == 60) {
				m1 += 1;
				s1 = 0;
			}
			if (m1 == 60) {
				h1 += 1;
				m1 = 0;
			}
			if (h1 == 24) {
				h1 = 0;
			}
			int x = h1 * 10000 + m1 * 100 + s1;
			if (x % 3 == 0) ans += 1;

			if (h1 == h2 && m1 == m2 && s1 == s2) break;
			s1 += 1;
		}

		cout << ans << "\n";
	}
}