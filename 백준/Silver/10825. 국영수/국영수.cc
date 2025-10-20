#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<string>> v(N, vector<string>(4));

    for (int i = 0; i < N; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2] >> v[i][3];
    }

    sort(v.begin(), v.end(), [](const vector<string>& a, const vector<string>& b) {
        if (stoi(a[1]) != stoi(b[1])) {
            return stoi(a[1]) > stoi(b[1]); // 국어 점수를 기준으로 내림차순
        }
        else if (stoi(a[2]) != stoi(b[2])) {
            return stoi(a[2]) < stoi(b[2]); // 영어 점수를 기준으로 오름차순
        }
        else if (stoi(a[3]) != stoi(b[3])) {
            return stoi(a[3]) > stoi(b[3]); // 수학 점수를 기준으로 내림차순
        }
        else {
            return a[0] < b[0]; // 이름 기준으로 오름차순
        }
        });

    for (int i = 0; i < N; i++) {
        cout << v[i][0] << "\n";
    }
}