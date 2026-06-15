#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    stack<int> s;
    for (int a : arr) {
        if (!s.empty() && s.top() == a) continue;
        s.push(a);
    }
    
    while (!s.empty()) {
        answer.push_back(s.top());
        s.pop();
    }
    
    reverse(answer.begin(), answer.end());

    return answer;
}