#include <bits/stdc++.h>

class CString {
    int size;
    char *a;
public:
    explicit CString(int n = 0) {
        size = n;
        a = new char[size];
    }
    CString(const CString &lhs) {
        size = lhs.size;
        a = new char[size];
        for (int i = 0; i < size; ++i) {
            a[i] = lhs.a[i];
        }
    }
    CString(const char *p) {
        size = sizeof(p);
        a = new char[size];
        for (int i = 0; i < size; ++i) {
            a[i] = p[i];
        }
    }
    ~CString() {
        size = 0;
        delete [] a;
    }
    friend std::istream &operator>>(std::istream &is, CString &lhs) {
        std::cout << "Nhap vao do chuoi ki tu: ";
        is >> lhs.size;
        lhs.a = new char[lhs.size];
        std::cout << "Nhap vao xau: ";
        for (int i = 0; i < lhs.size; ++i) {
            is >> lhs.a[i];
        }
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const CString &lhs) {
        os << "Chuoi ki tu la: ";
        os << lhs.a;
        return os;
    }
    friend CString operator+(const CString &lhs, const CString &rhs) {
        CString res(lhs.size + rhs.size);
        for (int i = 0; i < lhs.size; ++i) {
            res.a[i] = lhs.a[i];
        }
        for (int i = 0; i < rhs.size; ++i) {
            res.a[lhs.size + i] = rhs.a[i];
        }
        return res;
    }
    friend bool operator==(const CString &lhs, const CString &rhs) {
        if (lhs.size != rhs.size) {
            return false;
        }
        for (int i = 0; i < lhs.size; ++i) {
            if (lhs.a[i] != rhs.a[i]) {
                return false;
            }
        }
        return true;
    }
    friend bool operator!=(const CString &lhs, const CString &rhs) {
        if (lhs.size != rhs.size) {
            return true;
        }
        for (int i = 0; i < lhs.size; ++i) {
            if (lhs.a[i] != rhs.a[i]) {
                return true;
            }
        }
        return false;
    }
    friend bool operator<(const CString &lhs, const CString &rhs) {
        int mn = std::min(lhs.size, rhs.size);
        for (int i = 0; i < mn; ++i) {
            if (lhs.a[i] < rhs.a[i]) {
                return true;
            }
        }
        if (lhs.size != rhs.size) {
            return lhs.size < rhs.size;
        }
        return false;
    }
    friend bool operator<=(const CString &lhs, const CString &rhs) {
        return lhs < rhs || lhs == rhs;
    }
    friend bool operator>(const CString &lhs, const CString &rhs) {
        return rhs < lhs;
    }
    friend bool operator>=(const CString &lhs, const CString &rhs) {
        return lhs > rhs || lhs == rhs;
    }
};

int main() {

    CString a;
    std::cin >> a;
    std::cout << a << "\n";

    CString b;
    std::cin >> b;
    std::cout << b << "\n";

    CString c = "hello";
    std::cout << c << "\n";

    CString sum = a + b;
    std::cout << sum << "\n";

    if (a == b) {
        std::cout << "Chuoi a bang chuoi b\n";
    }
    if (a != b) {
        std::cout << "Chuoi a khac chuoi b\n";
    }
    if (a < b) {
        std::cout << "Chuoi a nho hon chuoi b\n";
    }
    if (a <= b) {
        std::cout << "Chuoi a nho hon bang chuoi b\n";
    }
    if (a > b) {
        std::cout << "Chuoi a lon hon chuoi b\n";
    }
    if (a >= b) {
        std::cout << "Chuoi a lon hon bang chuoi b\n";
    }

    return 0;
}