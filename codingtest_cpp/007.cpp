// https://school.programmers.co.kr/learn/courses/30/lessons/49994
#include <string>
#include <vector>
using namespace std;

int bx[4] = {-1, 1, 0, 0};
int by[4] = {0, 0, 1, -1};
vector<vector<vector<int>>> board(2, vector<vector<int>>(11, vector<int>(11, 0)));
int solution(string dirs) {
    int answer = 0;
    int dirsize = dirs.length();
    int x = 5;
    int y = 5;
    int index = 0;
    for (int i = 0; i < dirsize; i++) {
        switch (dirs[i]) {
           case 'U':
               index = 0;
               break;
           case 'D':
               index = 1;
               break;
           case 'R':
               index = 2;
               break;
           case 'L':
               index = 3;
               break;
        }
        int nx = x + bx[index];
        int ny = y + by[index];
        if (nx < 0 || ny < 0 || nx > 10 || ny > 10) continue;
        if (!board[index / 2][(nx + x) / 2][(ny + y) / 2]) {
            board[index / 2][(nx + x) / 2][(ny + y) / 2] = 1;
            answer++;
        }
        x = nx;
        y = ny;
    }
    return answer;
}
