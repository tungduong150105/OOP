#include <bits/stdc++.h>

class cNhanVien {
    std::string sMNV;
    std::string sHoTen;
    int iTuoi;
    std::string sSDT;
    std::string sEmail;
    int iLuongCoBan;
public:
    void input() {
        std::cout << "Nhap vao ma nhan vien: ";
        std::cin >> sMNV;
        std::cin.ignore();
        std::cout << "Nhap vao ho ten: ";
        std::getline(std::cin, sHoTen);
        std::cout << "Nhap vao tuoi: ";
        std::cin >> iTuoi;
        std::cout << "Nhap vao so dien thoai: ";
        std::cin >> sSDT;
        std::cout << "Nhap vao luong co ban: ";
        std::cin >> iLuongCoBan;
    }
    void output() {
        std::cout << "Ma nhan vien la: " << sMNV << "\n";
        std::cout << "Ho ten la: " << sHoTen << "\n";
        std::cout << "Tuoi la: " << iTuoi << "\n";
        std::cout << "So dien thoai la: " << sSDT << "\n";
        std::cout << "Luong co ban la: " << iLuongCoBan << "\n";
    }
    int GetLuongCoBan() {
        return iLuongCoBan;
    }
};

class cLapTrinhVien : public cNhanVien {
    int iOvertime;
public:
    void input() {
        cNhanVien::input();
        std::cout << "Nhap vao so gio overtime: ";
        std::cin >> iOvertime;
    }
    void output() {
        cNhanVien::output();
        std::cout << "So gio overtime la: " << iOvertime << "\n";
    }
    int64_t TinhLuong() {
        return (int64_t) GetLuongCoBan() + (int64_t) iOvertime * 200000;
    }
};

class cKiemChungVien : public cNhanVien {
    int iSoLoiPhatHien;
public:
    void input() {
        cNhanVien::input();
        std::cout << "Nhap vao so loi phat hien: ";
        std::cin >> iSoLoiPhatHien;
    }
    void output() {
        cNhanVien::output();
        std::cout << "So loi phat hien la: " << iSoLoiPhatHien << "\n";
    }
    int64_t TinhLuong() {
        return (int64_t) GetLuongCoBan() + (int64_t) iSoLoiPhatHien * 50000;
    }
};

class cDanhSach {
    int n, m;
    cLapTrinhVien *a;
    cKiemChungVien *b;
public:
    cDanhSach() {
        n = 0;
        m = 0;
        a = new cLapTrinhVien[0];
        b = new cKiemChungVien[0];
    }
    ~cDanhSach() {
        n = 0;
        m = 0;
        delete [] a;
        delete [] b;
    }
    void input() {
        std::cout << "Nhap vao so lap trinh vien: ";
        std::cin >> n;
        a = new cLapTrinhVien[n];
        std::cout << "Nhap vao so kiem chung vien: ";
        std::cin >> m;
        b = new cKiemChungVien[m];
        std::cout << "\n";
        std::cout << "Nhap danh sach lap trinh vien\n";
        for (int i = 0; i < n; ++i) {
            std::cout << "Nhap thong tin lap trinh vien: \n";
            a[i].input();
            std::cout << "\n";
        }
        std::cout << "Nhap danh sach kiem chung vien\n";
        for (int i = 0; i < m; ++i) {
            std::cout << "Nhap thong tin kiem chung vien: \n";
            b[i].input();
            std::cout << "\n";
        }
    }
    void output() {
        if (n) {
            std::cout << "Danh sach lap trinh vien la\n";
            for (int i = 0; i < n; ++i) {
                a[i].output();
                std::cout << "-----\n";
            }
        }
        if (m) {
            std::cout << "Danh sach kiem chung vien la\n";
            for (int i = 0; i < m; ++i) {
                b[i].output();
                std::cout << "-----\n";
            }
        }
        std::cout << "\n";
    }
    double TinhLuongTrungBinh() {
        double ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (double) a[i].TinhLuong();
        }
        for (int i = 0; i < m; ++i) {
            ans += (double) b[i].TinhLuong();
        }
        ans /= (double) (n + m);
        return ans;
    }
    void DanhSachLuongThapHonTrungBinh() {
        bool flag = false;
        double res = TinhLuongTrungBinh();
        for (int i = 0; i < n; ++i) {
            if ((double) a[i].TinhLuong() < res) {
                if (!flag) {
                    std::cout << "Danh sach nhan vien co luong thap hon luong trung binh la:\n";
                }
                flag = true;
                a[i].output();
                std::cout << "-----\n";
            }
        }
        for (int i = 0; i < m; ++i) {
            if ((double) b[i].TinhLuong() < res) {
                if (!flag) {
                    std::cout << "Danh sach nhan vien co luong thap hon luong trung binh la:\n";
                }
                flag = true;
                b[i].output();
                std::cout << "-----\n";
            }
        }
        if (!flag) {
            std::cout << "Khong co nhan vien nao co luong thap hon luong trung binh\n";
        }
    }
};

int main() {

    cDanhSach DS;
    DS.input();

    DS.output();

    DS.DanhSachLuongThapHonTrungBinh();

    return 0;
}
