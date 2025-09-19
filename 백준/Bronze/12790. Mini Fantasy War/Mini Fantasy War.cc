#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    vector<tuple<int, int, int, int, int, int, int, int>> v;
    int a, b, c, d, e, f, g, h;
    for (int i = 0; i < T; i++) {
        cin >> a >> b >> c >> d >> e >> f >> g >> h;    
        v.push_back({a, b, c, d, e, f, g, h});
    }
    
    for (int i = 0; i < T; i++) {
        int hp = get<0>(v[i]) + get<4>(v[i]);
        if (hp < 1) hp = 1;
        
        int mp = get<1>(v[i]) + get<5>(v[i]);
        if (mp < 1) mp = 1;
        
        int atk = get<2>(v[i]) + get<6>(v[i]);
        if (atk < 0) atk = 0;
        
        int def = get<3>(v[i]) + get<7>(v[i]);
        
        cout << hp + 5 * mp + 2 * atk + 2 * def << "\n";
    }
}