#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string add(string a, string b) {
	int i = a.size() - 1;
	int j = b.size() - 1;
	int carry = 0;

	string res = "";

	while (i >= 0 || j >= 0 || carry) {
		int sum = carry;

		if (i >= 0) sum += a[i--] - '0';
		if (j >= 0) sum += b[j--] - '0';

		res.push_back(char('0' + (sum % 10)));
		carry = sum / 10;
	}

	reverse(res.begin(), res.end());

	return res;
}

string calculate(vector<int> v, string sum) {
	if (v.size() == 1) return sum;

	int last_value = -1;
	int state = 0; // 0: start, 1: rise, 2: descent
	vector<int> min_max_value;
	for (int i = 0; i < v.size(); i++) {
		if (last_value == v[i]) continue;

		if (i == 0) {
			min_max_value.push_back(v[i]);
		}
		else {
			if ((state == 1 && last_value > v[i])
				|| (state == 2 && last_value < v[i])) min_max_value.push_back(last_value);

			if (last_value < v[i]) state = 1;
			else state = 2;
		}

		last_value = v[i];
	}

	if (last_value != -1) min_max_value.push_back(last_value);

	if (min_max_value.size() == 1) return sum;

	bool odd = true;
	if (min_max_value[0] < min_max_value[1]) odd = false;

	vector<int> new_v;
	for (int i = 0; i < min_max_value.size(); i++) {
		if ((odd && i % 2 == 0)
			|| (!odd && i % 2 != 0)) {
			new_v.push_back(min_max_value[i]);
			continue;
		}

		if (i == 0) {
			sum = add(sum, to_string(min_max_value[i + 1] - min_max_value[i]));
		}
		else if (i == min_max_value.size() - 1) {
			sum = add(sum, to_string(min_max_value[i - 1] - min_max_value[i]));
		}
		else {
			if (min_max_value[i + 1] - min_max_value[i] <= min_max_value[i - 1] - min_max_value[i]) {
				sum = add(sum, to_string(min_max_value[i + 1] - min_max_value[i]));
			}
			else {
				sum = add(sum, to_string(min_max_value[i - 1] - min_max_value[i]));
			}
		}
	}

	return calculate(new_v, sum);
}

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << calculate(a, "0");
}