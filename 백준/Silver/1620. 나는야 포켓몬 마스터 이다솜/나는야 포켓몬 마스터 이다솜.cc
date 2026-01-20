#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string name[100001];
unordered_map <string, int> num;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> name[i];
		num[name[i]] = i;
	}

	string q;
	for (int i = 0; i < m; i++) {
		cin >> q;
		if (q[0] - '0' >= 0 && q[0] - '0' <= 9) {
			cout << name[stoi(q)];
		}
		else {
			cout << num[q];
		}
		cout << "\n";
	}
}