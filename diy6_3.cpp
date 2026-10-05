#include <iostream>
using namespace std;

class Array {
    int *a, size;

public:
    Array(int n) {
        size = n;
        a = new int[n];
    }

    int& operator[](int i) {
        if (i < 0 || i >= size) {
            throw "Index out of range";
        }
        return a[i];
    }

    ~Array() {
        delete[] a;
    }
};

int main() {
    Array a(5);

    try {
        a[0] = 10;
        a[4] = 50;
        cout << a[0] << " " << a[4] << endl;
        cout << a[5];
    }
    catch (const char* e) {
        cout << e;
    }
}