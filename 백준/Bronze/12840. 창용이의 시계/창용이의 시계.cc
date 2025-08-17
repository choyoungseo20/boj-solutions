#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, m, s;
    cin >> h >> m >> s;

    int q;
    cin >> q;

    int T, c;
    int tmp_h, tmp_m, tmp_s;
    int carry, tmp;
    while (q--) {
        cin >> T;

        if (T == 1) {
            cin >> c;

            c %= 86400;
            tmp_h = c / 3600;
            c %= 3600;
            tmp_m = c / 60;
            c %= 60;
            tmp_s = c;

            tmp = s + tmp_s;
            carry = tmp / 60;
            s = tmp % 60;

            tmp = m + tmp_m + carry;
            carry = tmp / 60;
            m = tmp % 60;

            tmp = h + tmp_h + carry;
            h = tmp % 24;
        }
        else if (T == 2) {
            cin >> c;

            c %= 86400;
            tmp_h = c / 3600;
            c %= 3600;
            tmp_m = c / 60;
            c %= 60;
            tmp_s = c;

            tmp = s - tmp_s + 60;
            if (tmp < 60) carry = 1;
            else carry = 0;
            s = tmp % 60;

            tmp = m - tmp_m - carry + 60;
            if (tmp < 60) carry = 1;
            else carry = 0;
            m = tmp % 60;

            tmp = h - tmp_h - carry + 24;
            h = tmp % 24;
        }
        else {
            cout << h << " " << m << " " << s << "\n";
        }
    }
}