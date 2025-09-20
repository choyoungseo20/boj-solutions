#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> v;
    int A;
    for (int i = 0; i < N; i++) {
        cin >> A;
        v.push_back(A);
    }
    
    sort(v.begin(), v.end());
    
    cout << v[v.size() - 1];
}