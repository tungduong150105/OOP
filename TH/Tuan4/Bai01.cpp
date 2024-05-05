#include <bits/stdc++.h>

class cComplex {
    double dReal, dImg;
public:
    cComplex();
    friend std::istream &operator>>(std::istream &, cComplex &);
    friend std::ostream &operator<<(std::ostream &, const cComplex &);
    friend cComplex operator+(const cComplex &, const cComplex &);
    friend cComplex operator-(const cComplex &, const cComplex &);
    friend cComplex operator*(const cComplex &, const cComplex &);
    friend cComplex operator/(const cComplex &, const cComplex &);
    friend bool operator==(const cComplex &, const cComplex &);
    friend bool operator!=(const cComplex &, const cComplex &);
};

cComplex::cComplex() {
    dReal = 0;
    dImg = 0;
}

std::istream &operator>>(std::istream &is, cComplex &lhs) {
    std::cout << "Nhap phan thuc: ";
    is >> lhs.dReal;
    std::cout << "Nhap phan ao: ";
    is >> lhs.dImg;
    return is;
}

std::ostream &operator<<(std::ostream &os, const cComplex &lhs) {
    os << lhs.dReal << (lhs.dImg == std::abs(lhs.dImg) ? " + " : " - ") << std::abs(lhs.dImg) << "i";
    return os;
}

cComplex operator+(const cComplex &lhs, const cComplex &rhs) {
    cComplex res;
    res.dReal = lhs.dReal + rhs.dReal;
    res.dImg = lhs.dImg + rhs.dImg;
    return res;
}

cComplex operator-(const cComplex &lhs, const cComplex &rhs) {
    cComplex res;
    res.dReal = lhs.dReal - rhs.dReal;
    res.dImg = lhs.dImg - rhs.dImg;
    return res;
}

cComplex operator*(const cComplex &lhs, const cComplex &rhs) {
    cComplex res;
    res.dReal = lhs.dReal * rhs.dReal - lhs.dImg * rhs.dImg;
    res.dImg = lhs.dImg * rhs.dReal + lhs.dReal * rhs.dImg;
    return res;
}

cComplex operator/(const cComplex &lhs, const cComplex &rhs) {
    cComplex res;
    double div = rhs.dReal * rhs.dReal + rhs.dImg * rhs.dImg;
    if (div != 0) {
        res.dReal = (lhs.dReal * rhs.dReal + lhs.dImg * rhs.dImg) / div;
        res.dImg = (lhs.dImg * rhs.dReal - lhs.dReal * rhs.dImg) / div;
    } else {
        std::cout << "Error.\n";
    }
    return res;
}

bool operator==(const cComplex &lhs, const cComplex &rhs) {
    return lhs.dReal == rhs.dReal && lhs.dImg == rhs.dImg;
}

bool operator!=(const cComplex &lhs, const cComplex &rhs) {
    return lhs.dReal != rhs.dReal || lhs.dImg != rhs.dImg;
}

int main() {
    cComplex cp1, cp2;

    std::cin >> cp1 >> cp2;

    std::cout << "Tong 2 so phuc la: " << (cp1 + cp2) << "\n";
    std::cout << "Hieu 2 so phuc la: " << (cp1 - cp2) << "\n";
    std::cout << "Tich 2 so phuc la: " << (cp1 * cp2) << "\n";
    std::cout << "Thuong 2 so phuc la: " << (cp1 / cp2) << "\n";

    if (cp1 == cp2) {
        std::cout << "Hai so phuc bang nhau\n";
    } else if (cp1 != cp2) {
        std::cout << "Hai so phuc khac nhau\n";
    }

    return 0;
}
