#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int max = -1000001;
    int min = 1000001;
    int tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        if (tmp > max) max = tmp;
        if (tmp < min) min = tmp;
    }
    
    cout << min << " " << max;
}