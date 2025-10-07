#include <iostream>

using namespace std;

int A[1000001] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;
    
    int num;
    for (int i = 1; i <= N; i++) {
        cin >> num;
        A[i] = num ^ A[i - 1];
    }
    
    int ans = 0;
    int s, e;
    while (Q--) {
        cin >> s >> e;
        ans ^= A[e] ^ A[s - 1];
    }
    
    cout << ans;
}