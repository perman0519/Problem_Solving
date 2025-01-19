#include <iostream>
using namespace std;

void div2(int &b) {
    b = b / 2;
}

void incision1(int &b) {
    b = b / 10; 
}

int main() {
    int a, b;
    cin >> a >> b;
    if (a == b) {
        cout << 1;
        return 0;
    }
    int cnt = 1;
    while (a < b) {
        bool check_one = b - ((b / 10) * 10) == 1;
        if (b % 2 == 1 && check_one == false) {
            cout << -1;
            return 0;
        }
        if (b % 2 == 1 && check_one == true)
            incision1(b);
        else 
            div2(b);
        cnt++;
        if (a == b) {
            cout << cnt;
            return 0;
        }
    }
    cout << -1;
}