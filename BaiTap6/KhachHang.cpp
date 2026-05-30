#include "KhachHang.h"
#include <fstream>

KhachHang::KhachHang() {
	donGiaHang = 0;
	soLuongHang = 0;
	tienTra = 0;
}

void KhachHang::nhap(ifstream& fin) {
	fin >> ten >> soLuongHang >> donGiaHang;
}

void KhachHang::xuat(ofstream& fout) {
	fout << ten << endl;
	fout << tinhTienTra() << endl;
}

double KhachHang::getTien() {
	return tinhTienTra();
}