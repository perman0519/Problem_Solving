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
	bool operator== (Power op2); // == 연산자 함수 선언
};

void Power::show() {
	cout << "kick=" << kick << ','
	<< "punch=" << punch << endl;
}

bool Power::operator==(Power op2) {
	if(kick==op2.kick && punch==op2.punch) return true;
	else return false;
}

int main() {
	Power a(3,5), b(3,5);
	a.show();
	b.show();
	if(a==b) cout << "같다" << endl;
	else cout << "다르다" << endl;
}


