#include <iostream>
#include <cstring>
using namespace std;

class Text {
    char *buf;
public:
    Text(const char *s = "") { 
        buf = new char[strlen(s) + 1]; 
        strcpy(buf, s); 
    }
    
    Text(const Text &o) { 
        buf = new char[strlen(o.buf) + 1]; 
        strcpy(buf, o.buf); 
    }
    
    Text& operator=(const Text &o) {
        if (this != &o) {
            delete[] buf;
            buf = new char[strlen(o.buf) + 1];
            strcpy(buf, o.buf);
        }
        return *this;
    }
    
    ~Text() { 
        delete[] buf; 
    }
    
    void show() const { 
        cout << buf << endl; 
    }
};

int main() {
    Text a("alpha"), b("beta");
    b = a;
    a.show(); 
    b.show();
    return 0;
}