#include "KiemChungVien.h"
#include <iostream>

void KiemChungVien::nhap() {
	NhanVien::nhap();
	cout << "Nhap so loi phat hien: "; cin >> soLoiPhatHien;
}


void KiemChungVien::xuat() {
	NhanVien::xuat();
	cout << "So loi phat hien: " << soLoiPhatHien << endl;
	cout << "Luong: " << tinhLuong() << endl;
}


long double KiemChungVien::tinhLuong() {
	return luongCoBan + soLoiPhatHien * DON_GIA_TREN_SO_LOI;
}

string KiemChungVien::getLoaiNV() {
	return "Kiem chung vien";
}