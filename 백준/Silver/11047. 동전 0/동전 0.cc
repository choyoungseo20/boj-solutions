#include <iostream>
#include <vector>

using namespace std;

vector<int> V;

int main() {
    int N, K;
    int idx;
    
    cin >> N >> K;
    
    for (int i = 0; i < N; i++) {
        int in;
        cin >> in;
        
        if (in <= K) idx = i;
        
        V.push_back(in);
    }
    
    int ans = 0;
    
    while (1) {
        if (idx == -1) break;
        if (V[idx] <= K) {
            ans += K / V[idx];
            K %= V[idx];
        }
        idx--;
    }
   
    cout << ans;
}