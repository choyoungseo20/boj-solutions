#include <string>
#include <vector>

using namespace std;

int dp[1000001][2];

int rob(int s, int e, vector<int>& money) {
    dp[s][s] = money[s];
    dp[s + 1][s] = max(money[s], money[s + 1]);
    
    for (int i = s + 2; i <= e; i++) {
        dp[i][s] = max(dp[i - 1][s], dp[i - 2][s] + money[i]);
    }
    
    return dp[e][s];
}

int solution(vector<int> money) {
    int n = money.size();
    int c1 = rob(0, n - 2, money);
    int c2 = rob(1, n - 1, money);
    
    return max(c1, c2);
}