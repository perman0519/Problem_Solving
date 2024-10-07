#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다)" << endl;
    while (1) {
        cout << ">>";
        string str;
        getline(cin, str);
        if (str == "exit") {
            break;
        }
        int length = str.length();
        for (int i = 0; i < length / 2; i++) {
            swap(str[i], str[length - i - 1]);
        }
        cout << str << endl;
    }
}