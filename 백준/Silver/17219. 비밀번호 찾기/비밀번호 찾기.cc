#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, string> pw;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	string address, password;
	for (int i = 0; i < n; i++) {
		cin >> address >> password;
		pw[address] = password;
	}

	for (int i = 0; i < m; i++) {
		cin >> address;
		cout << pw[address] << "\n";
	}
}