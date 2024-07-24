#include <bits/stdc++.h>
using namespace std;

void R(std::deque<int>& dq) {
	if (dq.size() == 0)
		return ;
    size_t left = 0;
    size_t right = dq.size() - 1;

    while (left < right) {
        // 양 끝의 원소를 교환
        std::swap(dq[left], dq[right]);

        // 양쪽에서 한 칸씩 안쪽으로 이동
        ++left;
        --right;
    }
}

void D(deque<int> &dq) {
	dq.pop_front();
}

vector<string> split(const string &str, char delimiter) {
	vector<string> ret;
	string token;
	istringstream tokenStream(str);
	while (getline(tokenStream, token, delimiter)) {
		ret.push_back(token);
	}
	return ret;
}

int main(void) { //AC
	cout.sync_with_stdio(0);
	cin.tie(0);
	int T, N;
	cin >> T;
	while (T--)
	{
		deque<int> dq;
		string p, arr;
		cin >> p;
		cin >> N;
		cin >> arr;
		bool err = false;

		if (arr.front() == '[' && arr.back() == ']') {
			arr = arr.substr(1, arr.length() - 2);
		}

		vector<string> arr_split = split(arr, ',');
		for (size_t i = 0; i < arr_split.size(); i++)
		{
			dq.push_back(atoi(arr_split[i].c_str()));
		}
		bool reverse = false;
		int reverse_cnt = 0;
		for (size_t i = 0; i < p.size(); i++)
		{
			if (p[i] == 'R') {
				++reverse_cnt;
			}
			else {
				if (reverse_cnt % 2 != 0) {
					if (reverse == true)
						reverse = false;
					else
						reverse = true;
				}
				reverse_cnt = 0;
				if (dq.empty()) {
					err = true;
					break;
				}
				else {
		 			if (reverse == true)
						dq.pop_back();
					else
						dq.pop_front();
				}
			}
		}
		if (reverse_cnt % 2 != 0) {
			if (reverse == true)
				reverse = false;
			else
				reverse = true;
		}
		if (err == true) {
			cout << "error\n";
		}
		else {
			cout << '[';
			int size = dq.size();
			if (reverse == true) {
				while (size--) {
					cout << dq.back();
					if (size != 0)
						cout << ',';
					dq.pop_back();
				}
			}
			else {
				while (size--) {
					cout << dq.front();
					if (size != 0)
						cout << ',';
					dq.pop_front();
				}
			}
			cout << ']';
			cout << '\n';
		}
	}
	return 0;
}
