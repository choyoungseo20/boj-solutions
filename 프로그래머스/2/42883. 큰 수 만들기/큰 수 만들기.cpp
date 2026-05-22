#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    stack<int> s;
    for (int i = 0; i < number.size(); i++) {
        int num = number[i] - '0';
        while (k > 0 && !s.empty() && num > s.top()) {
            s.pop();
            k--;
        }
        s.push(num);
    }
    while (k > 0) {
        s.pop();
        k--;
    }
    while (!s.empty()) {
        answer.push_back(s.top() + '0');
        s.pop();
    }
    reverse(answer.begin(), answer.end());
    return answer;
}