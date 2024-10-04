#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> player(0, 0);
pair<int, int> camera(0, -1);

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string cmd;
		cin >> cmd;
		int dx = player.first - camera.first;
		int dy = player.second - camera.second;
		int mpx = 0, mpy = 0, mcx = 0, mcy = 0;
		if (cmd == "W") {
			mpx = dx;
			mpy = dy;
			mcx = dx;
			mcy = dy;
		}
		else if (cmd == "A") {
			// dx = -dy;
			// dy = dx;
			mpx = -dy;
			mpy = dx;
			mcx = -dy;
			mcy = dx;

		}
		else if (cmd == "S") {
			// dx = -dx;
			// dy = -dy;
			mpx = -dx;
			mpy = -dy;
			mcx = -dx;
			mcy = -dy;
		}
		else if (cmd == "D") {
			// dx = dy;
			// dy = -dx;
			mpx = dy;
			mpy = -dx;
			mcx = dy;
			mcy = -dx;
		}
		else if (cmd == "MR") {
			mcx = dx;
			mcy = dy;
			mcx += -dy;
			mcy += dx;
		}
		else { // cmd == ML
			mcx = dx;
			mcy = dy;
			mcx += dy;
			mcy += -dx;
		}
		player.first += mpx;
		player.second += mpy;
		camera.first += mcx;
		camera.second += mcy;
		cout << player.first << ' ' << player.second << ' ' << camera.first << ' ' << camera.second << endl;
	}
}
