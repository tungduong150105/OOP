#include <bits/stdc++.h>

class cSinhVien {
    std::string sMSSV;
    std::string sHoTen;
    std::string sDiaChi;
    int iTongTinChi;
    double dDTB;
public:
    void Nhap () {
        std::cout << "Nhap ma so sinh vien: ";
        std::cin >> sMSSV;
        std::cin.ignore();
        std::cout << "Nhap ho ten: ";
        std::getline(std::cin, sHoTen);
        std::cout << "Nhap dia chi: ";
        std::getline(std::cin, sDiaChi);
        std::cout << "Nhap tong so tin chi: ";
        std::cin >> iTongTinChi;
        std::cout << "Nhap diem trung binh: ";
        std::cin >> dDTB;
    }
    void Xuat() {
        std::cout << "Ma so sinh vien la: " << sMSSV << "\n";
        std::cout << "Ho ten la: " << sHoTen << "\n";
        std::cout << "Dia chi la: " << sDiaChi << "\n";
        std::cout << "Tong so tin chi la: " << iTongTinChi << "\n";
        std::cout << "Diem trung binh la: " << dDTB << "\n";
    }
    int GetTinhChi() {
        return iTongTinChi;
    }
    double GetDTB() {
        return dDTB;
    }
};

class cSinhVienCaoDang : public cSinhVien {
    double dDiemThiTotNghiep;
public:
    void Nhap () {
        cSinhVien::Nhap();
        std::cout << "Nhap diem thi tot nghiep: ";
        std::cin >> dDiemThiTotNghiep;
    }
    void Xuat() {
        cSinhVien::Xuat();
        std::cout << "Diem thi tot nghiep la: " << dDiemThiTotNghiep << "\n";
    }
    bool XetTotNghiep() {
        return GetTinhChi() >= 120 && GetDTB() >= 5.0 && dDiemThiTotNghiep >= 5.0;
    }
};

class cSinhVienDaiHoc : public cSinhVien {
    std::string sTenLuanVan;
    double dDiemLuanVan;
public:
    void Nhap() {
        cSinhVien::Nhap();
        std::cin.ignore();
        std::cout << "Nhap ten luan van: ";
        std::getline(std::cin, sTenLuanVan);
        std::cout << "Nhap diem luan van: ";
        std::cin >> dDiemLuanVan;
    }
    void Xuat() {
        cSinhVien::Xuat();
        std::cout << "Ten luan van la: " << sTenLuanVan << "\n";
        std::cout << "Diem luan van la: " << dDiemLuanVan << "\n";
    }
    bool XetTotNghiep() {
        return GetTinhChi() >= 170 && GetDTB() >= 5.0 && dDiemLuanVan >= 5.0;
    }
};

int main() {
    cSinhVienCaoDang a;
    std::cout << "Nhap thong tin sinh vien 1:\n";
    a.Nhap();

    cSinhVienDaiHoc b;
    std::cout << "Nhap thong tin sinh vien 2:\n";
    b.Nhap();

    if (a.XetTotNghiep()) {
        std::cout << "Sinh vien 1 du dieu kien tot nghiep\n";
    } else {
        std::cout << "Sinh vien 1 khong du dieu kien tot nghiep\n";
    }

    if (b.XetTotNghiep()) {
        std::cout << "Sinh vien 2 du dieu kien tot nghiep\n";
    } else {
        std::cout << "Sinh vien 2 khong du dieu kien tot nghiep\n";
    }

    std::cout << "Thong tin sinh vien 1 la:\n";
    a.Xuat();

    std::cout << "-----\n";

    std::cout << "Thong tin sinh vien 2 la:\n";
    b.Xuat();

    return 0;
}
