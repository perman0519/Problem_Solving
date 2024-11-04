#include <iostream>
using namespace std;

class Rect;
bool equal(Rect r, Rect s);

class Rect {
	int width, height;

public:
	Rect(int width, int height) {
		this->width = width;
		this->height = height;
	}
	friend bool equal(Rect r, Rect s);
};

bool equal(Rect r, Rect s) {
	if (r.width == s.width && r.height == s.height) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	Rect a(3, 4), b(5, 6);
	if (equal(a, b)) {
		cout << "equal" << endl;
	}
	else {
		cout << "not equal" << endl;
	}
	return 0;
}
