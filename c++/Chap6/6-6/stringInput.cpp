#include <iostream>
using namespace std;

class MyVector {
    int *p;
    int size;

public:
    MyVector(int n = 100);
    ~MyVector() { delete[] p; }
};

MyVector::MyVector(int n) {
    size = n;
    p = new int[n];
}

int main() {
    MyVector *v1, *v2;
    v1 = new MyVector();
    v2 = new MyVector(1024);

    delete v1;
    delete v2;
}