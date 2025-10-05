#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    int N;
    string word;
    
    cin >> N;
    
    int count = 0;
    while (N--) {
        cin >> word;
        
        stack<char> S;
        for (char c : word) {
            if (S.empty() != 1 && S.top() == c) S.pop();
            else S.push(c);
        }
        
        if (S.empty()) count++;
    }
    
    cout << count;
}