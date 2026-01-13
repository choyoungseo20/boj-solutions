#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

bool is_digit(char c) {
	return 0 <= c - '0' && c - '0' <= 9;
}

bool is_op(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

bool is_left_bracket(char c) {
	return c == '(';
}

bool is_right_bracket(char c) {
	return c == ')';
}

bool validate(string str) {
	int validate_brackets = 0;
	bool possible = true;
	int last_char_state = 1; // 0은 number, 1은 op, 2는 left bracket, 3은 right bracket
	// 제일 처음에는 number or left bracket만 올 수 있음 -> op와 같음

	for (int i = 0; i < str.size(); i++) {
		char current_char = str[i];

		// number 다음에는 number or op or right bracket만 올 수 있음
		if (last_char_state == 0) {
			if (is_digit(current_char)) {
				last_char_state = 0;
			}
			else if (is_op(current_char)) {
				last_char_state = 1;
			}
			else if (is_right_bracket(current_char)) {
				last_char_state = 3;
				if (validate_brackets > 0) {
					validate_brackets--;
				}
				else {
					possible = false;
					break;
				}
			}
			else {
				possible = false;
				break;
			}
		}
		// op 다음에는 number or left bracket만 올 수 있음
		// left bracket 다음에는 number or left bracket만 올 수 있음
		else if (last_char_state == 1 || last_char_state == 2) {
			if (is_digit(current_char)) {
				last_char_state = 0;
			}
			else if (is_left_bracket(current_char)) {
				last_char_state = 2;
				validate_brackets++;
			}
			else {
				possible = false;
				break;
			}
		}
		// right bracket 다음에는 op or right bracket만 올 수 있음
		else if (last_char_state == 3) {
			if (is_op(current_char)) {
				last_char_state = 1;
			}
			else if (is_right_bracket(current_char)) {
				last_char_state = 3;
				if (validate_brackets > 0) {
					validate_brackets--;
				}
				else {
					possible = false;
					break;
				}
			}
			else {
				possible = false;
				break;
			}
		}
	}

	if (!possible || validate_brackets != 0 || last_char_state == 1 || last_char_state == 2) {
		return false;
	}
	return true;
}

string delete_zero(string num) {
	bool is_minus = false;

	if (!num.empty() && num[0] == '-') {
		is_minus = true;
		num = num.substr(1);
	}

	bool is_zero = true;
	string res;
	for (int i = 0; i < num.size(); i++) {
		if (num[i] != '0') {
			is_zero = false;
			res = num.substr(i);
			break;
		}
	}

	if (is_zero) return "0";
	if (is_minus) return "-" + res;
	return res;
}

bool is_smaller(string num1, string num2) {
	num1 = delete_zero(num1);
	num2 = delete_zero(num2);

	if (num1.size() != num2.size())
		return num1.size() < num2.size();
	return num1 < num2;
}

string add(string num1, string num2) {
	int i = num1.size() - 1;
	int j = num2.size() - 1;
	int carry = 0;

	string res;

	while (i >= 0 || j >= 0 || carry) {
		int sum = carry;

		if (i >= 0) sum += num1[i--] - '0';
		if (j >= 0) sum += num2[j--] - '0';

		res.push_back(char('0' + (sum % 10)));
		carry = sum / 10;
	}

	reverse(res.begin(), res.end());
	return delete_zero(res);
}

string sub(string num1, string num2) {
	int i = num1.size() - 1;
	int j = num2.size() - 1;
	int borrow = 0;

	string res;

	while (i >= 0) {
		int a = num1[i--] - '0' - borrow;
		int b = (j >= 0 ? num2[j--] - '0' : 0);

		if (a < b) {
			a += 10;
			borrow = 1;
		}
		else {
			borrow = 0;
		}

		res.push_back(char('0' + (a - b)));
	}

	reverse(res.begin(), res.end());

	return delete_zero(res);
}

string mul(string num1, string num2) {
	if (num1 == "0" || num2 == "0") return "0";

	int n = num1.size(), m = num2.size();
	vector<int> v(n + m, 0);

	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			int mult = (num1[i] - '0') * (num2[j] - '0');
			int sum = mult + v[i + j + 1];
			v[i + j + 1] = sum % 10;
			v[i + j] += sum / 10;
		}
	}

	string res;
	int i = 0;
	while (i < v.size() && v[i] == 0) i++;
	for (; i < v.size(); i++) res.push_back(v[i] + '0');

	return delete_zero(res);
}

string div(string num1, string num2) {
	string cur = "";
	string res = "";

	for (char c : num1) {
		cur.push_back(c);
		cur = delete_zero(cur);

		int cnt = 0;
		while (!is_smaller(cur, num2)) {
			cur = sub(cur, num2);
			cnt++;
		}
		res.push_back(cnt + '0');
	}

	return delete_zero(res);
}

string calculate_op(string num1, string num2, char op) {
	string res;

	if (op == '+') {
		bool is_minus = false;
		if (num1[0] != '-' && num2[0] == '-') {
			return calculate_op(num1, num2.substr(1), '-');
		}
		else if (num1[0] == '-' && num2[0] != '-') {
			return calculate_op(num2, num1.substr(1), '-');
		}
		else if (num1[0] == '-' && num2[0] == '-') {
			is_minus = true;
			num1 = num1.substr(1);
			num2 = num2.substr(1);
		}

		res = add(num1, num2);

		if (is_minus) {
			res = "-" + res;
		}
	}
	else if (op == '-') {
		bool is_minus = false;
		if (num1[0] != '-' && num2[0] == '-') {
			return calculate_op(num1, num2.substr(1), '+');
		}
		else if (num1[0] == '-' && num2[0] != '-') {
			return calculate_op(num1, "-" + num2, '+');
		}
		else if (num1[0] == '-' && num2[0] == '-') {
			return calculate_op(num2.substr(1), num1.substr(1), '-');
		}

		if (is_smaller(num1, num2)) {
			is_minus = true;
			string tmp = num1;
			num1 = num2;
			num2 = tmp;
		}

		res = sub(num1, num2);

		if (is_minus) {
			res = "-" + res;
		}
	}
	else if (op == '*') {
		bool is_minus = false;
		if (num1[0] != '-' && num2[0] == '-') {
			is_minus = true;
			num2 = num2.substr(1);
		}
		else if (num1[0] == '-' && num2[0] != '-') {
			is_minus = true;
			num1 = num1.substr(1);
		}
		else if (num1[0] == '-' && num2[0] == '-') {
			num1 = num1.substr(1);
			num2 = num2.substr(1);
		}

		res = mul(num1, num2);

		if (is_minus) {
			res = "-" + res;
		}
	}
	else if (op == '/') {
		bool is_minus = false;
		if (num1[0] != '-' && num2[0] == '-') {
			is_minus = true;
			num2 = num2.substr(1);
		}
		else if (num1[0] == '-' && num2[0] != '-') {
			is_minus = true;
			num1 = num1.substr(1);
		}
		else if (num1[0] == '-' && num2[0] == '-') {
			num1 = num1.substr(1);
			num2 = num2.substr(1);
		}

		if (delete_zero(num2) == "0") {
			return "ROCK";
		}

		res = div(num1, num2);

		if (is_minus) {
			res = "-" + res;
		}
	}

	return res;
}

bool visited[1001];

string calculate(string str, int idx) {
	stack<string> number;
	stack<char> op;
	string num = "0";
	for (int i = idx; i < str.size(); i++) {
		if (visited[i]) continue;
		visited[i] = true;

		if (is_digit(str[i])) {
			num += str[i];
		}
		else if (is_op(str[i])) {
			number.push(num);
			num = "0";

			if (!op.empty() && (op.top() == '*' || op.top() == '/')) {
				string num2 = number.top();
				number.pop();
				string num1 = number.top();
				number.pop();

				num1 = delete_zero(num1);
				num2 = delete_zero(num2);
				string new_num = calculate_op(num1, num2, op.top());
				if (new_num == "ROCK") {
					return "ROCK";
				}
				number.push(new_num);

				op.pop();
				op.push(str[i]);
			}
			else {
				op.push(str[i]);
			}
		}
		else if (is_left_bracket(str[i])) {
			num = calculate(str, i + 1);
		}
		else if (is_right_bracket(str[i])) {
			break;
		}
	}

	number.push(num);
	num = "0";
	while (!op.empty()) {
		string num2 = number.top();
		number.pop();
		string num1 = number.top();
		number.pop();

		num1 = delete_zero(num1);
		num2 = delete_zero(num2);

		char o = op.top();
		op.pop();
		if (!op.empty() && op.top() == '-') {
			op.pop();
			op.push('+');

			if (num1[0] == '-') num1 = num1.substr(1);
			else num1 = "-" + num1;
		}
		string new_num = calculate_op(num1, num2, o);
		if (new_num == "ROCK") {
			return "ROCK";
		}
		number.push(new_num);
	}

	return delete_zero(number.top());
}

int main() {
	string str;
	cin >> str;

	bool possible = validate(str);

	if (!possible) {
		cout << "ROCK";
		return 0;
	}

	string ans = calculate(str, 0);

	cout << ans;
}