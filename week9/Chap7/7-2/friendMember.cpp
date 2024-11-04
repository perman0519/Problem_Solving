#include <iostream>
using namespace std;
class Rect;

class RectManager { // RectManager 클래스 선언
public:
	bool equals(Rect r, Rect s);
};

class Rect {
	int width, height;
public:
	Rect(int width, int height) {
		this->width = width;
		this->height = height;
	}
	friend bool RectManager::equals(Rect r, Rect s);
};

bool RectManager::equals(Rect r, Rect s) {
	if (r.width == s.width && r.height == s.height) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	Rect a(3, 4), b(5, 6);
	RectManager manager;
	if (manager.equals(a, b)) {
		cout << "equal" << endl;
	}
	else {
		cout << "not equal" << endl;
	}
	return 0;
}
