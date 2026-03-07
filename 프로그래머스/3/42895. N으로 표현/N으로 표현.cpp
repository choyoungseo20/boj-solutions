#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

unordered_map<int, bool> um;
set<int> s[9];

int solution(int N, int number) {
    int answer = -1;
    
    int tmp_n = N;
    for (int i = 1; i < 9; i++) {
        s[i].insert(tmp_n);
        
        if (tmp_n == number) return i;
        
        tmp_n = tmp_n * 10 + N;
    }
    
    for (int i = 2; i < 9; i++) {
        for (int j = 1; j <= i / 2; j++) {
            for (auto x : s[j]) {
                for (auto y : s[i - j]) {
                    s[i].insert(x + y);
                    if (x + y == number) return i;
                    s[i].insert(x * y);
                    if (x * y == number) return i;
                    if (abs(x - y) != 0) {
                        s[i].insert(abs(x - y));
                        if (abs(x - y) == number) return i;
                    }
                    if (x / y > 0) {
                        s[i].insert(x / y);
                        if (x / y == number) return i;
                    }
                    if (y / x > 0) {
                        s[i].insert(y / x);
                        if (y / x == number) return i;
                    }
                }
            }
        }
    }
    
    return answer;
}