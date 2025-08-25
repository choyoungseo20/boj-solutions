#include <iostream>
#include <cmath>

using namespace std;

void hanoi(int N, int a, int b, int c) {
    if (N == 1) {
        cout << a << " " << c << "\n";
    }
    else {
        hanoi(N - 1, a, c, b);
        cout << a << " " << c << "\n";
        hanoi(N - 1, b, a, c);
    }
}

int main() {
    int N;
    cin >> N;
    cout << int(pow(2, N)) - 1 << "\n";

    hanoi(N, 1, 2, 3);
}