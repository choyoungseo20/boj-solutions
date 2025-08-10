#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> V(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }

    if (next_permutation(V.begin(), V.end())) {
        for (int i = 0; i < N; i++) {
            cout << V[i] << " ";
        }
    }
    else {
        cout << -1;
    }
}