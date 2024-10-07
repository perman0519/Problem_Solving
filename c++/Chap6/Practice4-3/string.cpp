#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    cout << "문자열 입력>> ";
    string str;
    getline(cin, str);
    // find 'a' in str using find() function
    int pos = str.find('a');
    int count = 0;
    while (pos != string::npos) {
        count++;
        pos = str.find('a', pos + 1);
    }
    cout << "문자 a는 " << count << "개 있습니다." << endl;
}