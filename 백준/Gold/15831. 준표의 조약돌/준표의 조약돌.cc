#include <iostream>
#include <string>

using namespace std;

int main() {
    int N, B, W;
    string S;
    
    cin >> N >> B >> W;
    cin >> S;
    
    int ans = 0;
    
    int i = 0, j = 0;
    int B_count = 0, W_count = 0;
    
    if (S[0] == 'B') B_count++;
    else W_count++;
    
    while(1) {
        if (B >= B_count && W <= W_count) {
            if (j - i + 1 > ans) ans = j - i + 1;
        }
        if (i == j && i == S.length() - 1) break;     
        
        if (B >= B_count || i == j) {
            if (j < S.length() - 1) {
                j++;
                if (S[j] == 'B') B_count++;
                else W_count++;
            }
            else {
                if (S[i] == 'B') B_count--;
                else W_count--;
                i++;   
            }
            
        }
        else if (B < B_count) {
            if (S[i] == 'B') B_count--;
            else W_count--;
            i++;           
        }
    }
    
    cout << ans;
}