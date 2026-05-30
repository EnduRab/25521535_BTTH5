#include "SinhVienDaiHoc.h"
#include <iostream>

void SinhVienDaiHoc::nhap() {
	SinhVien::nhap();
	cin.ignore(1000, '\n');
	cout << "Nhap ten luan van: "; getline(cin, tenLuanVan);
	cout << "Nhap diem luan van: "; cin >> diemLuanVan;
}

void SinhVienDaiHoc::xuat() {
	SinhVien::xuat();
	cout << "Ten luan van: " << tenLuanVan << endl;
	cout << "Diem luan van: " << diemLuanVan << endl;
	cout << "Du dieu kien tot nghiep: " << (xetTN() == true ? "Co" : "Khong") << endl;
}

bool SinhVienDaiHoc::xetTN() {
	if (tongSoTinChi >= 170 && diemTB >= 5 && diemLuanVan >= 5) return true;
	return false;
}

string SinhVienDaiHoc::getLoaiSV() {
	return "Dai hoc";
}