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
    void setH(int H) {
        iH = H;
    }
    void setM(int M) {
        iM = M;
    }
    void setS(int S) {
        iS = S;
    }
    int getH() const {
        return iH;
    }
    int getM() const {
        return iM;
    }
    int getS() const {
        return iS;
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

class CTime {
    int iH, iM, iS;
public:
    CTime(int H = 0, int M = 0, int S = 0) : iH(H), iM(M), iS(S) {}
    CTime(const CTime &lhs) {
        iH = lhs.iH;
        iM = lhs.iM;
        iS = lhs.iS;
    }
    friend std::istream &operator>>(std::istream &is, CTime &lhs) {
        std::cout << "Nhap vao thoi diem\n";
        std::cout << "Nhap vao so gio: ";
        is >> lhs.iH;
        std::cout << "Nhap vao so phut: ";
        is >> lhs.iM;
        std::cout << "Nhap vao so giay: ";
        is >> lhs.iS;
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const CTime &lhs) {
        os << "Thoi diem la: " << lhs.iH << " gio, " << lhs.iM << " phut, " << lhs.iS << " giay\n";
        return os;
    }
    friend CTime operator+(const CTime &lhs, const int &rhs) {
        CTime res = lhs;
        int t0 = lhs.iH * 60 * 60 + lhs.iM * 60 + lhs.iS;
        t0 += rhs;
        t0 %= 86400;
        res.iH = t0 / 3600;
        t0 %= 3600;
        res.iM = t0 / 60;
        t0 %= 60;
        res.iS = t0;
        return res;
    }
    friend CTime operator-(const CTime &lhs, const int &rhs) {
        CTime res = lhs;
        int t0 = lhs.iH * 60 * 60 + lhs.iM * 60 + lhs.iS;
        t0 -= rhs;
        assert(t0 >= 0);
        t0 %= 86400;
        res.iH = t0 / 3600;
        t0 %= 3600;
        res.iM = t0 / 60;
        t0 %= 60;
        res.iS = t0;
        return res;
    }
    friend CTimeSpan operator-(const CTime &lhs, const CTime &rhs) {
        CTimeSpan res;
        int t0 = lhs.iH * 60 * 60 + lhs.iM * 60 + lhs.iS;
        int t1 = rhs.iH * 60 * 60 + rhs.iM * 60 + rhs.iS;
        int diff = t0 - t1;
        assert(diff >= 0);
        diff %= 86400;
        res.setH(diff / 3600);
        diff %= 3600;
        res.setM(diff / 60);
        diff %= 60;
        res.setS(diff);
        return res;
    }
    friend CTime operator+(const CTime &lhs, const CTimeSpan &rhs) {
        CTime res;
        int t0 = lhs.iH * 60 * 60 + lhs.iM * 60 + lhs.iS;
        int t1 = rhs.getH() * 60 * 60 + rhs.getM() * 60 + rhs.getS();
        int tot = t1 + t0;
        tot %= 86400;
        res.iH = tot / 3600;
        tot %= 3600;
        res.iM = tot / 60;
        tot %= 60;
        res.iS = tot;
        return res;
    }
    CTime operator++() {
        ++iS;
        int addM = iS / 60;
        iS %= 60;
        iM += addM;
        int addH = iM / 60;
        iM %= 60;
        iH += addH;
        iH %= 24;
        return *this;
    }
    CTime operator--() {
        --iS;
        int subM = iS < 0 ? -1 : 0;
        iS += 60;
        iS %= 60;
        iM += subM;
        int subH = iM < 0 ? -1 : 0;
        iM += 60;
        iM %= 60;
        iH += subH;
        iH += 24;
        iH %= 24;
        return *this;
    }
};

int main() {
    CTime a;
    std::cin >> a;

    int add;
    std::cout << "Nhap vao so giay: ";
    std::cin >> add;

    CTime b = a + add;
    CTime c = a - add;

    std::cout << "Thoi diem sao khi them " << add << " giay la: \n" << b;
    std::cout << "Thoi diem sao khi giam " << add << " giay la: \n" << c;

    CTime d;
    std::cin >> d;

    CTimeSpan diff = a - d;

    std::cout << "Khoang thoi gian giua 2 thoi diem la: \n" << diff;
    return 0;
}