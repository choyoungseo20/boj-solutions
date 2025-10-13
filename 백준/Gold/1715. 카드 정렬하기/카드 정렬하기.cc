#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        pq.push(num);
    }

    // 묶음의 개수가 1개일 경우
    if (N == 1) cout << 0;
    else {
        int a, b;
        int ans = 0;

        // 작은 두 수부터 더하기
        // 먼저 합쳐진 수는 후에 합칠 때마다 계속 더하기 때문
        while (1) {
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();

            ans += a + b;

            if (pq.empty()) break;

            pq.push(a + b);
        }

        cout << ans;
    }
}