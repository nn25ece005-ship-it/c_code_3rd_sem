#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

class Fraction {
    int n, d;

public:
    Fraction(int a = 0, int b = 1) {
        int g = gcd(a, b);
        n = a / g;
        d = b / g;
    }

    friend istream& operator>>(istream& in, Fraction& f) {
        in >> f.n >> f.d;
        int g = gcd(f.n, f.d);
        f.n /= g;
        f.d /= g;
        return in;
    }

    friend ostream& operator<<(ostream& out, Fraction f) {
        return out << f.n << "/" << f.d;
    }
};

int main() {
    Fraction f;

    cout << "Enter numerator and denominator: ";
    cin >> f;

    cout << "Fraction: " << f;
}