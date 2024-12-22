#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    cout.sync_with_stdio(0);

    int n;
    cin >> n;
    unordered_map<int, int> count_map;

    for (int i = 0; i < n; i++) {
        int q;
        cin >> q;
        count_map[q]++;
    }

    int m;
    cin >> m;
    vector<int> vm(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> vm[i];
    }
    for (int i = 0; i < m; i++) {
        cout << count_map[vm[i]] << ' ';
    }
    return 0;
}
