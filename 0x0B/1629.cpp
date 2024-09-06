#include <iostream>

using namespace std;

long long func1(long long a, long long b, long long c) {
    int ret;
    if (b == 1)
        return a % c;
    long long val = func1(a, b / 2, c);
    val = val * val % c;
    if (b % 2 == 0)
        return val;
    return val * a % c;
}

int main(void) {
    long long a, b, c;
    cin >> a >> b >> c;
    cout << func1(a, b, c);
}