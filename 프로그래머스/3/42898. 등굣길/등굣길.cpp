#include <string>
#include <vector>

using namespace std;

const int mod = 1000000007;
int dp[101][101];
bool block[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    for (int i = 0; i < puddles.size(); i++) {
        block[puddles[i][1]][puddles[i][0]] = true;
    }
    
    dp[1][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (block[i][j]) continue;
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }
    
    return dp[n][m];
}