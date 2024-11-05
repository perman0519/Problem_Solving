#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> r(n, 0);
    vector<int> g(n, 0);
    vector<int> b(n, 0);
    for (int i = 0; i < n; i++) {
        vector<int> tmp(3, 0);
        cin >> r[i] >> g[i] >> b[i];
    }
    int d[n + 1][3];
    d[0][0] = r[0];
    d[0][1] = g[0];
    d[0][2] = b[0];
    for (int i = 1; i < n; i++) {
        d[i][0] = min(d[i - 1][1], d[i - 1][2]) + r[i];
        d[i][1] = min(d[i - 1][0], d[i - 1][2]) + g[i];
        d[i][2] = min(d[i - 1][0], d[i - 1][1]) + b[i];
    }
    cout << min({d[n-1][0], d[n-1][1], d[n-1][2]});
    return 0;
}
