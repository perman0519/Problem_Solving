#include <iostream>
#include <string>
using namespace std;

class Book {
    string title;
    int price;

public:
    Book(const string& title, int price);
    Book(const Book& b);
    ~Book() = default;
    void set(const string& title, int price);
    void show() const { cout << title << ' ' << price << "원" << endl; }
};

Book::Book(const string& title, int price) {
    this->title = title;
    this->price = price;
}

Book::Book(const Book& b) {
    title = b.title;
    price = b.price;
}

void Book::set(const string& title, int price) {
    this->title = title;
    this->price = price;
}

int main() {
    Book cpp("명품C++", 10000);
    Book java = cpp;
    java.set("명품자바", 12000);
    cpp.show();
    java.show();
}