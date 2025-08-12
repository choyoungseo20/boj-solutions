#include <iostream>
#include <queue>

using namespace std;

char map[11][11];
bool visited[11][11][11][11];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int rr, rc, br, bc;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'R') {
                rr = i;
                rc = j;
                map[i][j] = '.';
            }
            if (map[i][j] == 'B') {
                br = i;
                bc = j;
                map[i][j] = '.';
            }
        }
    }

    queue < pair<pair<pair<int, int>, pair<int, int>>, int>> q;

    visited[rr][rc][br][bc] = true;
    q.push({ {{rr, rc}, {br, bc}}, 0 });

    while (!q.empty()) {
        int nrr = q.front().first.first.first;
        int nrc = q.front().first.first.second;
        int nbr = q.front().first.second.first;
        int nbc = q.front().first.second.second;
        int dist = q.front().second;
        q.pop();

        if (dist >= 10) {
            cout << -1;
            return 0;
        }

        // 왼쪽으로 기울이기
        rr = nrr, rc = nrc, br = nbr, bc = nbc;
        if (bc < rc) {
            while (map[br][bc - 1] == '.') bc = bc - 1;
            while (map[rr][rc - 1] == '.' && (rr != br || rc - 1 != bc)) rc = rc - 1;

            if (map[br][bc - 1] != 'O') {
                if (map[rr][rc - 1] == 'O') {
                    cout << dist + 1;
                    return 0;
                }

                if (!visited[rr][rc][br][bc]) {
                    visited[rr][rc][br][bc] = true;
                    q.push({ {{rr, rc}, {br, bc}}, dist + 1 });
                }
            } 
        }
        else {
            while (map[rr][rc - 1] == '.') rc = rc - 1;
            while (map[br][bc - 1] == '.' && (rr != br || rc != bc - 1)) bc = bc - 1;

            if (map[br][bc - 1] != 'O') {
                if (map[rr][rc - 1] == 'O') {
                    if (map[br][bc - 2] != 'O') {
                        cout << dist + 1;
                        return 0;
                    }
                }

                if (!visited[rr][rc][br][bc]) {
                    visited[rr][rc][br][bc] = true;
                    q.push({ {{rr, rc}, {br, bc}}, dist + 1 });
                }
            }
        }

        // 오른쪽으로 기울이기
        rr = nrr, rc = nrc, br = nbr, bc = nbc;
        if (bc > rc) {
            while (map[br][bc + 1] == '.') bc = bc + 1;
            while (map[rr][rc + 1] == '.' && (rr != br || rc + 1 != bc)) rc = rc + 1;

            if (map[br][bc + 1] != 'O') {
                if (map[rr][rc + 1] == 'O') {
                    cout << dist + 1;
                    return 0;
                }

                if (!visited[rr][rc][br][bc]) {
                    visited[rr][rc][br][bc] = true;
                    q.push({ {{rr, rc}, {br, bc}}, dist + 1 });
                }
            }
        }
        else {
            while (map[rr][rc + 1] == '.') rc = rc + 1;
            while (map[br][bc + 1] == '.' && (rr != br || rc != bc + 1)) bc = bc + 1;

            if (map[br][bc + 1] != 'O') {
                if (map[rr][rc + 1] == 'O') {
                    if (map[br][bc + 2] != 'O') {
                        cout << dist + 1;
                        return 0;
                    }
                }

                if (!visited[rr][rc][br][bc]) {
                    visited[rr][rc][br][bc] = true;
                    q.push({ {{rr, rc}, {br, bc}}, dist + 1 });
                }
            }   
        }

        // 위쪽으로 기울이기
        rr = nrr, rc = nrc, br = nbr, bc = nbc;
        if (br < rr) {
            while (map[br - 1][bc] == '.') br = br - 1;
            while (map[rr - 1][rc] == '.' && (rr - 1 != br || rc != bc)) rr = rr - 1;

            if (map[br - 1][bc] != 'O') {
                if (map[rr - 1][rc] == 'O') {
                    cout << dist + 1;
                    return 0;
                }

                if (!visited[rr][rc][br][bc]) {
                    visited[rr][rc][br][bc] = true;
                    q.push({ {{rr, rc}, {br, bc}}, dist + 1 });
                }
            }  
        }
        else {
            while (map[rr - 1][rc] == '.') rr = rr - 1;
            while (map[br - 1][bc] == '.' && (rr != br - 1 || rc != bc)) br = br - 1;

            if (map[br - 1][bc] != 'O') {
                if (map[rr - 1][rc] == 'O') {
                    if (map[br - 2][bc] != 'O') {
                        cout << dist + 1;
                        return 0;
                    }
                }

                if (!visited[rr][rc][br][bc]) {
                    visited[rr][rc][br][bc] = true;
                    q.push({ {{rr, rc}, {br, bc}}, dist + 1 });
                }
            }    
        }

        // 아래쪽으로 기울이기
        rr = nrr, rc = nrc, br = nbr, bc = nbc;
        if (br > rr) {
            while (map[br + 1][bc] == '.') br = br + 1;
            while (map[rr + 1][rc] == '.' && (rr + 1 != br || rc != bc)) rr = rr + 1;

            if (map[br + 1][bc] != 'O') {
                if (map[rr + 1][rc] == 'O') {
                    cout << dist + 1;
                    return 0;
                }

                if (!visited[rr][rc][br][bc]) {
                    visited[rr][rc][br][bc] = true;
                    q.push({ {{rr, rc}, {br, bc}}, dist + 1 });
                }
            }       
        }
        else {
            while (map[rr + 1][rc] == '.') rr = rr + 1;
            while (map[br + 1][bc] == '.' && (rr != br + 1 || rc != bc)) br = br + 1;

            if (map[br + 1][bc] != 'O') {
                if (map[rr + 1][rc] == 'O') {
                    if (map[br + 2][bc] != 'O') {
                        cout << dist + 1;
                        return 0;
                    }
                }

                if (!visited[rr][rc][br][bc]) {
                    visited[rr][rc][br][bc] = true;
                    q.push({ {{rr, rc}, {br, bc}}, dist + 1 });
                }
            }      
        }

    }

    cout << -1;

}