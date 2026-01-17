#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;

	stack<int> num;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] - '0' >= 0 && str[i] - '0' <= 9) {
			num.push(str[i] - '0');
		}
		else {
			int num2 = num.top();
			num.pop();
			int num1 = num.top();
			num.pop();

			if (str[i] == '+') {
				num.push(num1 + num2);
			}
			else if (str[i] == '-') {
				num.push(num1 - num2);
			}
			else if (str[i] == '*') {
				num.push(num1 * num2);
			}
			else if (str[i] == '/') {
				num.push(num1 / num2);
			}
		}
	}

	cout << num.top();
}