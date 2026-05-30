#include "KhachHangB.h"
#include <fstream>
#include <algorithm>

void KhachHangB::nhap(ifstream& fin) {
	KhachHang::nhap(fin);
	fin >> soNamThanThiet;
}

double KhachHangB::tinhTienTra() {
	phanTramKhuyenMai = max(soNamThanThiet * 0.05, 0.5);
	tienTra = (soLuongHang * donGiaHang) * (1 - phanTramKhuyenMai);
	tienTra *= (1 + VAT);
	return tienTra;
}

