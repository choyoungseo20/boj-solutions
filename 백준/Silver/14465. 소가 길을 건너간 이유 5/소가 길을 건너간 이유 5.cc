#include <iostream>

using namespace std;

bool broken[100001] = {false};

int main() {
    int N, K, B;
    cin >> N >> K >> B;
    
    int broken_idx;
    int fix_cnt = 0;
    int ans = 100001;
    for (int i = 0; i < B; i++) {
        cin >> broken_idx;
        if (broken_idx <= K) fix_cnt++;
        broken[broken_idx] = true;
    }
    
    int i = 1, j = K;
    
    while(1) {
        if (j == N + 1) break;
        if (ans > fix_cnt) ans = fix_cnt;
        
        if (broken[i]) fix_cnt--;
        i++;
        j++;
        if (broken[j]) fix_cnt++;
    }
    
    cout << ans;
}