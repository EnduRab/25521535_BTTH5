#include "LapTrinhVien.h"
#include <iostream>

void LapTrinhVien::nhap() {
	NhanVien::nhap();
	cout << "Nhap so gio overtime: "; cin >> soGioOT;
}


void LapTrinhVien::xuat() {
	NhanVien::xuat();
	cout << "So gio overtime: " << soGioOT << endl;
	cout << "Luong: " << tinhLuong() << endl;
}


long double LapTrinhVien::tinhLuong() {
	return luongCoBan + soGioOT * LUONG_OVERTIME;
}

string LapTrinhVien::getLoaiNV() {
	return "Lap trinh vien";
}