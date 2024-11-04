#include <iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick=0, int punch=0) {
		this->kick = kick; this->punch = punch;
	}
	void show();
	friend Power operator+ (int op1, Power op2); // + 연산자 함수 선언
};

void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power operator+(int op1, Power op2) {
	Power tmp; // 임시 객체 생성
	tmp.kick = op1 + op2.kick; // op1과 kick 더하기
	tmp.punch = op1 + op2.punch; // op1과 punch 더하기
	return tmp; // 임시 객체 리턴
}

int main() {
	Power a(3,5), b;
	a.show();
	b.show();
	b = 2 + a; // 정수와 파워 객체 더하기
	a.show();
	b.show();
}
