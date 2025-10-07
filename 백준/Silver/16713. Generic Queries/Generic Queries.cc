#include <iostream>

using namespace std;

int A[1000001];

int main() {
    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;
    
    int a;
    for (int i = 1; i <= N; i++) {
        cin >> a;
        A[i] = a ^ A[i - 1]; // XOR 연산자 ^
    }
    
    int ans = 0;
    int s, e;
    // XOR을 두 번 하면 원래대로 돌아오는 특성을 이용하여 누적합처럼 사용
    while (Q--) {
        cin >> s >> e;
        ans ^= A[e] ^ A[s - 1]; // XOR 연산자 ^
    }
    
    cout << ans;
}