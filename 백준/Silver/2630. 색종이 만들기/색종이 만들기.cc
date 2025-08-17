#include <iostream>

using namespace std;

int map[128][128];

int white_cnt = 0;
int blue_cnt = 0;

void find_ans(int N, int r, int c) {
    int find_white = false;
    int find_blue = false;

    for (int i = r; i < r + N; i++) {
        for (int j = c; j < c + N; j++) {
            if (map[i][j] == 0) find_white = true;
            else find_blue = true;
        }
    }

    if (find_white && find_blue) {
        find_ans(N / 2, r, c);
        find_ans(N / 2, r + N / 2, c);
        find_ans(N / 2, r, c + N / 2);
        find_ans(N / 2, r + N / 2, c + N / 2);
    }
    else {
        if (find_white) white_cnt++;
        else blue_cnt++;
    }
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    find_ans(N, 0, 0);

    cout << white_cnt << "\n";
    cout << blue_cnt << "\n";
}