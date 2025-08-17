#include <iostream>
#include <queue>

using namespace std;

bool visited[1001][1001];

int main() {
    int S;
    cin >> S;

    queue<pair<pair<int, int>, int>> q;
    visited[1][0] = true;
    q.push({ {1, 0}, 0 });

    while (!q.empty()) {
        int emoticon_num = q.front().first.first;
        int clipboard_num = q.front().first.second;
        int time = q.front().second;
        q.pop();

        if (emoticon_num == S) {
            cout << time;
            break;
        }
        
        if (!visited[emoticon_num][emoticon_num]) {
            visited[emoticon_num][emoticon_num] = true;
            q.push({ {emoticon_num, emoticon_num}, time + 1 });
        }
        if (emoticon_num + clipboard_num <= 1000 && !visited[emoticon_num + clipboard_num][clipboard_num]) {
            visited[emoticon_num + clipboard_num][clipboard_num] = true;
            q.push({ {emoticon_num + clipboard_num, clipboard_num}, time + 1 });
        }
        if (emoticon_num - 1 > 0 && !visited[emoticon_num - 1][clipboard_num]) {
            visited[emoticon_num - 1][clipboard_num] = true;
            q.push({ {emoticon_num - 1, clipboard_num}, time + 1 });
        }
    }
}