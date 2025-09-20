#include <iostream>
#include <string>

using namespace std;

int main() {
    string A;
    string B;
    cin >> A;
    
    int sum = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == ',') {
            sum += stoi(B);
            B = "";
        }
        else {
            B += A[i];
        }
    }
    cout << sum + stoi(B);
}