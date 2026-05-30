#include "GDCanHoChungCu.h"

void GDCanHoChungCu::nhap() {
	GiaoDich::nhap();
	cout << "Nhap ma can ho: "; cin >> maCan;
	cout << "Nhap vi tri tang: "; cin >> viTriTang;
}

void GDCanHoChungCu::xuat() {
	GiaoDich::xuat();
	cout << "Ma can ho: " << maCan << endl;
	cout << "Vi tri tang: " << viTriTang << endl;
	cout << "Thanh tien: " << tinhTien() << endl;
}

long double GDCanHoChungCu::tinhTien() {
	if (viTriTang == 1) return dienTich * donGia * 2;
	else if (viTriTang < 15) return dienTich * donGia;
	else return dienTich * donGia * 1.2;
}

LOAI_GIAO_DICH GDCanHoChungCu::getLoaiGiaoDich() {
	return LOAI_GIAO_DICH::CHUNG_CU;
} 