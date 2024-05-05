#include <bits/stdc++.h>

class CTimeSpan {
    int iH, iM, iS;
public:
    CTimeSpan(int H = 0, int M = 0, int S = 0) : iH(H), iM(M), iS(S) {}
    CTimeSpan(const CTimeSpan &lhs) {
        iH = lhs.iH;
        iM = lhs.iM;
        iS = lhs.iS;
    }
    friend std::istream &operator>>(std::istream &is, CTimeSpan &lhs) {
        std::cout << "Nhap vao khoang thoi gian\n";
        std::cout << "Nhap vao so gio: ";
        is >> lhs.iH;
        std::cout << "Nhap vao so phut: ";
        is >> lhs.iM;
        std::cout << "Nhap vao so giay: ";
        is >> lhs.iS;
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const CTimeSpan &lhs) {
        os << "Khoang thoi gian la: " << lhs.iH << " gio, " << lhs.iM << " phut, " << lhs.iS << " giay\n";
        return os;
    }
    friend CTimeSpan operator+(const CTimeSpan &lhs, const CTimeSpan &rhs) {
        CTimeSpan res;
        int t0 = lhs.iH * 60 * 60 + lhs.iM * 60 + lhs.iS;
        int t1 = rhs.iH * 60 * 60 + rhs.iM * 60 + rhs.iS;
        int tot = t1 + t0;
        res.iH = tot / 3600;
        tot %= 3600;
        res.iM = tot / 60;
        tot %= 60;
        res.iS = tot;
        return res;
    }
    friend CTimeSpan operator-(const CTimeSpan &lhs, const CTimeSpan &rhs) {
        CTimeSpan res;
        int t0 = lhs.iH * 60 * 60 + lhs.iM * 60 + lhs.iS;
        int t1 = rhs.iH * 60 * 60 + rhs.iM * 60 + rhs.iS;
        int diff = t0 - t1;
        if (diff < 0) {
            std::cout << "Khoang thoi gian dau phai lon hon thoi gian sau\n";
            return res;
        }
        // static_assert(diff >= 0, "Khoang thoi gian dau phai lon hon khoang thoi gian sau");
        res.iH = diff / 3600;
        diff %= 3600;
        res.iM = diff / 60;
        diff %= 60;
        res.iS = diff;
        return res;
    }
    friend bool operator==(const CTimeSpan &lhs, const CTimeSpan &rhs) {
        int t0 = lhs.iH * 60 * 60 + lhs.iM * 60 + lhs.iS;
        int t1 = rhs.iH * 60 * 60 + rhs.iM * 60 + rhs.iS;
        return t0 == t1;
    }
    friend bool operator!=(const CTimeSpan &lhs, const CTimeSpan &rhs) {
        int t0 = lhs.iH * 60 * 60 + lhs.iM * 60 + lhs.iS;
        int t1 = rhs.iH * 60 * 60 + rhs.iM * 60 + rhs.iS;
        return t0 != t1;
    }
    friend bool operator>(const CTimeSpan &lhs, const CTimeSpan &rhs) {
        int t0 = lhs.iH * 60 * 60 + lhs.iM * 60 + lhs.iS;
        int t1 = rhs.iH * 60 * 60 + rhs.iM * 60 + rhs.iS;
        return t0 > t1;
    }
    friend bool operator>=(const CTimeSpan &lhs, const CTimeSpan &rhs) {
        int t0 = lhs.iH * 60 * 60 + lhs.iM * 60 + lhs.iS;
        int t1 = rhs.iH * 60 * 60 + rhs.iM * 60 + rhs.iS;
        return t0 >= t1;
    }
    friend bool operator<(const CTimeSpan &lhs, const CTimeSpan &rhs) {
        int t0 = lhs.iH * 60 * 60 + lhs.iM * 60 + lhs.iS;
        int t1 = rhs.iH * 60 * 60 + rhs.iM * 60 + rhs.iS;
        return t0 < t1;
    }
    friend bool operator<=(const CTimeSpan &lhs, const CTimeSpan &rhs) {
        int t0 = lhs.iH * 60 * 60 + lhs.iM * 60 + lhs.iS;
        int t1 = rhs.iH * 60 * 60 + rhs.iM * 60 + rhs.iS;
        return t0 <= t1;
    }
};

int main() {
    CTimeSpan a;
    std::cin >> a;

    CTimeSpan b;
    std::cin >> b;

    CTimeSpan c = a + b;
    std::cout << "Tong 2 khoang thoi gian la:\n" << c << "\n";

    CTimeSpan d = a - b;
    if (a >= b) {
        std::cout << "Hieu 2 khoang thoi gian la:\n" << d << "\n";
    }

    if (a == b) {
        std::cout << "2 khoang thoi gian bang nhau\n";
    }

    if (a != b) {
        std::cout << "2 khoang thoi gian khac nhau\n";
    }

    if (a < b) {
        std::cout << "Khoang thoi gian dau nho hon khoang thoi gian sau\n";
    }

    if (a <= b) {
        std::cout << "Khoang thoi gian dau nho hon bang khoang thoi gian sau\n";
    }

    if (a > b) {
        std::cout << "Khoang thoi gian dau lon hon khoang thoi gian sau\n";
    }

    if (a >= b) {
        std::cout << "Khoang thoi gian dau lon hon bang khoang thoi gian sau\n";
    }

    return 0;
}