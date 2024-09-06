#include <iostream>

using namespace std;

// void func1(int n) {
//     if(n == 0) return ;
//     cout << n << ' ';
//     func1(n - 1);
// }

int func1(int a, int b, int m) {
    int val = 1;
    while (b--)
        val *= a;
    return val % m;
}
int main() {

    cout << func1(10, 2, 6);
}