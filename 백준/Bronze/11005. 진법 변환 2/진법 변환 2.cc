#include <iostream>
#include <string>

using namespace std;

int main() {
    int N, B;
    string ans = "";
    
    cin >> N >> B;
    
    while (N != 0) {
        int x = N % B;
        
        char c;
        if (x < 10) c = '0' + x;
        else c = 'A' + (x - 10);
        ans = c + ans;
        
        N /= B;
    }
    cout << ans;
}