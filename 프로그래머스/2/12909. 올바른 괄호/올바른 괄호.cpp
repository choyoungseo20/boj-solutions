#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> st;
    for (auto c : s) {
        if (st.empty()) st.push(c);
        else {
            if (st.top() == '(' && c == ')') {
                st.pop();
            }
            else {
                st.push(c);
            }
        }
    }
    
    if (!st.empty()) answer = false;

    return answer;
}