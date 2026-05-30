#include "GDDat.h"
#include <iostream>
#include <cctype>

void GDDat::nhap() {
	GiaoDich::nhap();
	bool hopLe = false;
	do {
		cout << "Nhap loai dat (A/B/C): "; cin >> loaiDat;
		hopLe = (loaiDat == 'A' || loaiDat == 'B' || loaiDat == 'C' ||
			loaiDat == 'a' || loaiDat == 'b' || loaiDat == 'c');
	} while (hopLe == false);

	if (islower(loaiDat)) {
		loaiDat = toupper(loaiDat);
	}
}

void GDDat::xuat() {
	GiaoDich::xuat();
	cout << "Loai dat: " << loaiDat << endl;
	cout << "Thanh tien: " << tinhTien() << endl;
}

long double GDDat::tinhTien() {
	if (loaiDat == 'A') {
		return dienTich * donGia * 1.5;
	}
	else {
		return dienTich * donGia;
	}
}

LOAI_GIAO_DICH GDDat::getLoaiGiaoDich() {
	return LOAI_GIAO_DICH::DAT;
}