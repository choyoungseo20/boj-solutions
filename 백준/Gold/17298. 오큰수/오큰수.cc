#include <iostream>
#include <stack>

using namespace std;

int ans[1000000];

int main() {
    int N;
    stack<pair<int, int>> s;

    cin >> N;

    int A;
    for (int i = 0; i < N; i++) {
        cin >> A;

        if (!s.empty()) {
            while (!s.empty() && s.top().first < A) {
                ans[s.top().second] = A;
                s.pop();
            }
            s.push({ A, i });
        }
        else s.push({ A, i });
    }

    while (!s.empty()) {
        ans[s.top().second] = -1;
        s.pop();
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
}