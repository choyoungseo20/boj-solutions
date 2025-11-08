#include <iostream>

using namespace std;

int main() {
    int A, B, C, D;

    cin >> A >> B >> C;
    cin >> D;

    int x = (A * 60 * 60 + B * 60 + C + D) % 86400;

    int h = x / 3600;
    int m = (x % 3600) / 60;
    int s = x % 60;

    cout << h << " " << m << " " << s;
}