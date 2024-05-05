#include <bits/stdc++.h>

class cPhanSo {
    int iTuSo;
    int iMauSo;
public:
    cPhanSo(int t = 0, int m = 1) {
        iTuSo = t;
        iMauSo = m;
    }
    cPhanSo(const cPhanSo &p) {
        iTuSo = p.iTuSo;
        iMauSo = p.iMauSo;
    }
    friend std::istream &operator>>(std::istream &is, cPhanSo &lhs) {
        std::cout << "Nhap tu so: ";
        is >> lhs.iTuSo;
        std::cout << "Nhap mau so: ";
        is >> lhs.iMauSo;
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const cPhanSo &lhs) {
        os << lhs.iTuSo << " / " << lhs.iMauSo;
        return os;
    }
    friend bool operator>(const cPhanSo &lhs, const cPhanSo &rhs) {
        return lhs.iTuSo * rhs.iMauSo > lhs.iMauSo * rhs.iTuSo;
    }
    friend cPhanSo operator+(const cPhanSo &lhs, const cPhanSo &rhs) {
        cPhanSo res;
        res.iMauSo = lhs.iMauSo * rhs.iMauSo;
        res.iTuSo = lhs.iTuSo * rhs.iMauSo + lhs.iMauSo * rhs.iTuSo;
        return res;
    }
    friend cPhanSo operator-(const cPhanSo &lhs, const cPhanSo &rhs) {
        cPhanSo res;
        res.iMauSo = lhs.iMauSo * rhs.iMauSo;
        res.iTuSo = lhs.iTuSo * rhs.iMauSo - lhs.iMauSo * rhs.iTuSo;
        return res;
    }
    friend cPhanSo operator*(const cPhanSo &lhs, const cPhanSo &rhs) {
        cPhanSo res;
        res.iMauSo = lhs.iMauSo * rhs.iMauSo;
        res.iTuSo = lhs.iTuSo * rhs.iTuSo;
        return res;
    }
    friend cPhanSo operator/(const cPhanSo &lhs, const cPhanSo &rhs) {
        cPhanSo res;
        res.iMauSo = lhs.iMauSo * rhs.iTuSo;
        res.iTuSo = lhs.iTuSo * rhs.iMauSo;
        return res;
    }
    friend bool operator==(const cPhanSo &lhs, const cPhanSo &rhs) {
        return lhs.iTuSo * rhs.iMauSo == lhs.iMauSo * rhs.iTuSo;
    }
    friend bool operator!=(const cPhanSo &lhs, const cPhanSo &rhs) {
        return lhs.iTuSo * rhs.iMauSo != lhs.iMauSo * rhs.iTuSo;
    }
};

int main() {
    cPhanSo a, b;
    std::cin >> a >> b;

    std::cout << "Tong 2 phan so la: " << a + b << "\n";
    std::cout << "Hieu 2 phan so la: " << a - b << "\n";
    std::cout << "Tich 2 phan so la: " << a * b << "\n";
    std::cout << "Thuong 2 phan so la: " << a / b << "\n";

    if (a != b) {
        std::cout << "2 phan so khac nhau\n";
    }
    if (a == b) {
        std::cout << "2 phan so bang nhau\n";
    }

    return 0;
}
