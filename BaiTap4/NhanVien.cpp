#include "NhanVien.h"
#include <iostream>

NhanVien::NhanVien() {
	maNhanVien = 0;
	luongCoBan = 0;
}

void NhanVien::nhap() {
	cout << "Nhap ma nhan vien: "; cin >> maNhanVien; cin.ignore(1000, '\n');
	cout << "Nhap ho va ten: "; getline(cin, hoTen);
	cout << "Nhap tuoi: "; cin >> tuoi; cin.ignore(1000, '\n');
	cout << "Nhap so dien thoai: "; getline(cin, soDienThoai);
	cout << "Nhap email: "; cin >> email;
	cout << "Nhap luong co ban: "; cin >> luongCoBan;
}

void NhanVien::xuat() {
	cout << "Ma nhan vien: " << maNhanVien << endl;
	cout << "Ho va ten: " << hoTen << endl;
	cout << "Tuoi: " << tuoi << endl;
	cout << "So dien thoai: " << soDienThoai << endl;
	cout << "Email: " << email << endl;
	cout << "Luong co ban: " << luongCoBan << endl;
}