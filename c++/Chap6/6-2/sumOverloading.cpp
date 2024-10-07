#include <iostream>
using namespace std;

int sum(int a, int b) {
    int ret = 0;
    for (int i = a; i <= b; i++) {
        ret += i;
    }
    return ret;
}

int sum(int a) {
    int ret = 0;
    for (int i = 1; i <= a; i++) {
        ret += i;
    }
    return ret;
}

int main() {
    cout << sum(3, 5) << endl;
    cout << sum(3) << endl;
    cout << sum(100) << endl;
}