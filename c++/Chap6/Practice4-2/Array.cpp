#include <iostream>
using namespace std;

int main() {
    int *arr = new int[5];
    float ret = 0;
    cout << "정수 5개 입력>> ";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
        ret += arr[i];
    }
    cout << "평균 " << ret / 5 << endl;
    delete[] arr;
}