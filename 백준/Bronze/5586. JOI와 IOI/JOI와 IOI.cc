#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    int joi = 0;
    int ioi = 0;
    for (int i = 0; i < s.size(); i++) {
        string tmp = s.substr(i, 3);
        if (tmp == "JOI") joi++;
        if (tmp == "IOI") ioi++;
    }
    
    cout << joi << "\n";
    cout << ioi;
}