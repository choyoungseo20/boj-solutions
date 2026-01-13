#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

/*
데이터를 추가해 주세요.

101912924번 제출이 통과합니다.

Input 1+(1/0)
Output 37318
Answer ROCK
*/

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

bool validate(string expr) {
	bool possible = true;

	// 열린 소괄호 개수
	int open_bracket_cnt = 0;

	// 0은 number, 1은 op, 2는 left bracket, 3은 right bracket
	// 제일 처음에는 number or left bracket만 올 수 있음 -> op와 같음
	int last_char_state = 1; 

	for (int i = 0; i < expr.size(); i++) {
		char current_char = expr[i];

		// number 다음에는 digit 또는 op 또는 right bracket 가능
		if (last_char_state == 0) {
			if (is_digit(current_char)) {
				last_char_state = 0;
			}
			else if (is_op(current_char)) {
				last_char_state = 1;
			}
			else if (is_right_bracket(current_char)) {
				last_char_state = 3;
				if (open_bracket_cnt > 0) {
					open_bracket_cnt--;
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
		// op 다음에는 digit 또는 left bracket 가능
		// left bracket 다음에는 digit 또는 left bracket 가능
		else if (last_char_state == 1 || last_char_state == 2) {
			if (is_digit(current_char)) {
				last_char_state = 0;
			}
			else if (is_left_bracket(current_char)) {
				last_char_state = 2;
				open_bracket_cnt++;
			}
			else {
				possible = false;
				break;
			}
		}
		// right bracket 다음에는 op or right bracket 가능
		else if (last_char_state == 3) {
			if (is_op(current_char)) {
				last_char_state = 1;
			}
			else if (is_right_bracket(current_char)) {
				last_char_state = 3;
				if (open_bracket_cnt > 0) {
					open_bracket_cnt--;
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

	// 불가능한 식 조합 || 열린 소괄호 || op로 끝날 경우 || left_bracket로 끝날 경우
	if (!possible || open_bracket_cnt != 0 || last_char_state == 1 || last_char_state == 2) {
		return false;
	}
	return true;
}

// 음수가 아닌 수의 불필요한 0 제거, 00001 -> 1
string delete_leading_zeros(string num) {
	bool is_zero = true;

	string res;

	int i = 0;
	for (int i = 0; i < num.size(); i++) {
		if (num[i] != '0') {
			is_zero = false;
			res = num.substr(i);
			break;
		}
	}

	if (is_zero) return "0";
	else return res;
}

// 음수가 아닌 두 수에서 num1이 num2보다 작은지 판단
bool is_smaller(string num1, string num2) {
	if (num1.size() != num2.size())
		return num1.size() < num2.size();
	return num1 < num2;
}

// 음수가 아닌 두 수의 덧셈
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

	return res;
}

// 음수가 아닌 두 수의 뺄셈, num1 > num2
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

	return delete_leading_zeros(res);
}

// 음수가 아닌 두 수의 곱셈
string mul(string num1, string num2) {
	if (num1 == "0" || num2 == "0") return "0";

	int n = num1.size();
	int m = num2.size();
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

	for (int i = 0; i < v.size(); i++) {
		res.push_back(v[i] + '0');
	}

	return delete_leading_zeros(res);
}

// 음수가 아닌 두 수의 나눗셈
string div(string num1, string num2) {
	string cur = "";
	string res = "";

	for (char c : num1) {
		cur.push_back(c);
		cur = delete_leading_zeros(cur);

		int cnt = 0;
		while (!is_smaller(cur, num2)) {
			cur = sub(cur, num2);
			cnt++;
		}
		res.push_back(cnt + '0');
	}

	return delete_leading_zeros(res);
}

// 두 수의 연산을 위한 전처리 및 분기 처리
string calculate_op(string num1, string num2, char op) {
	bool negative = false; // 계산 결과가 음수일 경우

	string res;

	if (op == '+') {
		if (num1[0] != '-' && num2[0] == '-') { // 1 + (-2)
			return calculate_op(num1, num2.substr(1), '-'); // 1 - 2
		}
		else if (num1[0] == '-' && num2[0] != '-') { // (-1) + 2
			return calculate_op(num2, num1.substr(1), '-'); // 2 - 1
		}
		else if (num1[0] == '-' && num2[0] == '-') { // (-1) + (-2)
			negative = true; // 음수
			num1 = num1.substr(1); // 1
			num2 = num2.substr(1); // 2
		}

		num1 = delete_leading_zeros(num1);
		num2 = delete_leading_zeros(num2);

		res = add(num1, num2);
	}
	else if (op == '-') {
		if (num1[0] != '-' && num2[0] == '-') { // 1 - (-2)
			return calculate_op(num1, num2.substr(1), '+'); // 1 + 2
		}
		else if (num1[0] == '-' && num2[0] != '-') { // (-1) - 2
			return calculate_op(num1, "-" + num2, '+'); // (-1) + (-2)
		}
		else if (num1[0] == '-' && num2[0] == '-') { // (-1) - (-2)
			return calculate_op(num2.substr(1), num1.substr(1), '-'); // 2 - 1
		}

		num1 = delete_leading_zeros(num1);
		num2 = delete_leading_zeros(num2);

		if (is_smaller(num1, num2)) { // 1 - 2
			negative = true; // 음수

			string tmp = num1;
			num1 = num2; // 2
			num2 = tmp; // 1
		}
		
		res = sub(num1, num2);
	}
	else if (op == '*') {
		if (num1[0] != '-' && num2[0] == '-') { // 1 * (-2)
			negative = true; // 음수
			num2 = num2.substr(1); // 2
		}
		else if (num1[0] == '-' && num2[0] != '-') { // (-1) * 2
			negative = true; // 음수
			num1 = num1.substr(1); // 1
		}
		else if (num1[0] == '-' && num2[0] == '-') { // (-1) * (-2)
			num1 = num1.substr(1); // 1
			num2 = num2.substr(1); // 2
		}

		num1 = delete_leading_zeros(num1);
		num2 = delete_leading_zeros(num2);

		res = mul(num1, num2);
	}
	else if (op == '/') {
		if (num1[0] != '-' && num2[0] == '-') { // 2 / (-1)
			negative = true; // 음수
			num2 = num2.substr(1); // 1
		}
		else if (num1[0] == '-' && num2[0] != '-') { // (-2) / 1
			negative = true; // 음수
			num1 = num1.substr(1); // 2
		}
		else if (num1[0] == '-' && num2[0] == '-') { // (-2) / (-1)
			num1 = num1.substr(1); // 2
			num2 = num2.substr(1); // 1
		}

		num1 = delete_leading_zeros(num1);
		num2 = delete_leading_zeros(num2);

		if (num2 == "0") { // 제수가 0일 경우 "ROCK" 반환
			return "ROCK";
		}

		res = div(num1, num2);
	}

	if (negative) return "-" + res; // 음수일 경우 - 부호 추가
	else return res;
}

bool visited[1001]; // 재귀함수로 expr을 확인하기 위함
string calculate(string expr, int idx) {
	stack<string> number;
	stack<char> op;

	string num = "";

	// 곱셈과 나눗셈을 우선적으로 계산
	// 소괄호가 시작될 경우 재귀적으로 calculate 함수 호출
	for (int i = idx; i < expr.size(); i++) {
		if (visited[i]) continue;
		visited[i] = true;

		if (is_digit(expr[i])) {
			num.push_back(expr[i]);
		}
		else if (is_op(expr[i])) {
			number.push(num);
			num = "";

			if (!op.empty() && (op.top() == '*' || op.top() == '/')) {
				string num2 = number.top();
				number.pop();
				string num1 = number.top();
				number.pop();

				string new_num = calculate_op(num1, num2, op.top());
				if (new_num == "ROCK") {
					return "ROCK";
				}
				number.push(new_num);

				op.pop();
				op.push(expr[i]);
			}
			else {
				op.push(expr[i]);
			}
		}
		else if (is_left_bracket(expr[i])) {
			num = calculate(expr, i + 1);
			if (num == "ROCK") {
				return "ROCK";
			}
		}
		else if (is_right_bracket(expr[i])) {
			break;
		}
	}

	number.push(num);

	// 뒤에서부터 역으로 계산
	// 덧셈과 뺄셈만 있을 경우 상관 없음
	// 맨 뒤의 op가 곱셈이나 나눗셈이어도 뒤에서부터 계산하기에 상관 없음
	while (!op.empty()) {
		string num2 = number.top();
		number.pop();
		string num1 = number.top();
		number.pop();

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

	return delete_leading_zeros(number.top());
}

int main() {
	string expr;
	cin >> expr;

	bool possible = validate(expr);

	if (!possible) {
		cout << "ROCK";
		return 0;
	}

	string ans = calculate(expr, 0);

	cout << ans;
}