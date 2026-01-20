#include <iostream>
#include <string>

using namespace std;

int main() {
	string expr;
	cin >> expr;

	int ans = 0;
	bool exist_minus = false;
	string num = "";
	for (int i = 0; i < expr.size(); i++) {
		if (expr[i] - '0' >= 0 && expr[i] - '0' <= 9) {
			num.push_back(expr[i]);
		}
		else {
			if (exist_minus) ans -= stoi(num);
			else ans += stoi(num);
			if (expr[i] == '-') exist_minus = true;
			num = "";
		}
	}
	if (exist_minus) ans -= stoi(num);
	else ans += stoi(num);

	cout << ans;
}