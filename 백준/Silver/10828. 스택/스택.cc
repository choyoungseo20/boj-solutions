#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    int N;
    stack<int> s;
    string cmd;
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> cmd;
        
        if (cmd == "push") {
            int X;
            cin >> X;
            s.push(X);
        }
        else if (cmd == "pop") {
            if (s.empty()) cout << -1 << "\n";
            else {
                cout << s.top() << "\n";
                s.pop();
            }
        }
        else if (cmd == "size") {
            cout << s.size() << "\n";
        }
        else if (cmd == "empty") {
            if (s.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if (cmd == "top") {
            if (s.empty()) cout << -1 << "\n";
            else {
                cout << s.top() << "\n";
            }
        }
    }
}