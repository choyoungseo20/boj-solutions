#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    string t[5];
    while (T--) {
        vector<pair<int, pair<int, int>>> v;
        for (int i = 0; i < 5; i++) {
            cin >> t[i];
            int h = stoi(t[i].substr(0, 2));
            int m = stoi(t[i].substr(3, 2));
            int time = h * 60 + m;

            h %= 12;

            int pos_h = h * 60 + m;
            int pos_m = m * 12;

            int diff = abs(pos_h - pos_m);
            int angle = min(diff, 720 - diff);

            v.push_back({ angle, { time, i } });
        }

        sort(v.begin(), v.end());

        int ans_pos = v[2].second.second;
        cout << t[ans_pos] << "\n";
    }
}