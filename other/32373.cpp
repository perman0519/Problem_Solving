#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    bool possible = true;
    for (int i = 0; i < n; i++) {
        int correct_pos = vec[i];
        if (abs(i - correct_pos) % k != 0) {
            possible = false;
            break;
        }
    }
    cout << (possible ? "Yes" : "No");
    return 0;
}
