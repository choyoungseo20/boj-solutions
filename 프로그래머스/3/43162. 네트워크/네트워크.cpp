#include <string>
#include <vector>

using namespace std;

bool visited[200];

void dfs(int c, int n, vector<vector<int>> computers) {
    for (int j = 0; j < n; j++) {
        if (computers[c][j] == 1 && !visited[j]) {
            visited[j] = true;
            dfs(j, n, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (computers[i][j] == 1 && !visited[j]) {
                visited[j] = true;
                answer++;
                dfs(j, n, computers);
            }
        }
    }
    return answer;
}