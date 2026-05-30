#include "GDNhaPho.h"
#include <iostream>

void GDNhaPho::nhap() {
	GiaoDich::nhap();
	int input;
	cout << "Nhap loai nha (0: Cao cap, 1: Thuong): "; cin >> input;
	loaiNha = (enum LOAI_NHA)input;
}

void GDNhaPho::xuat() {
	GiaoDich::xuat();
	cout << "Loai nha: ";
	if (loaiNha == LOAI_NHA::CAO_CAP) cout << "cao cap\n";
	else cout << "thuong\n";
	cout << "Thanh tien: " << tinhTien() << endl;
}

long double GDNhaPho::tinhTien() {
	if (loaiNha == LOAI_NHA::CAO_CAP) {
		return dienTich * donGia;
	}
	else return dienTich * donGia * 0.9;
}

LOAI_GIAO_DICH GDNhaPho::getLoaiGiaoDich() {
	return LOAI_GIAO_DICH::NHA_PHO;
}