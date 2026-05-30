#include "SinhVienCaoDang.h"
#include <iostream>

void SinhVienCaoDang::nhap() {
	SinhVien::nhap();
	cout << "Nhap diem thi Tot nghiep: "; cin >> diemThiTN;
}

void SinhVienCaoDang::xuat() {
	SinhVien::xuat();
	cout << "Diem thi tot nghiep: " << diemThiTN << endl;
	cout << "Du dieu kien tot nghiep: " << (xetTN() == true ? "Co" : "Khong") << endl;
}

bool SinhVienCaoDang::xetTN() {
	if (tongSoTinChi >= 120 && diemTB >= 5 && diemThiTN >= 5) return true;
	return false;
}

string SinhVienCaoDang::getLoaiSV() {
	return "Cao dang";
}