#include "NhanVienVanPhong.h"

const double LUONG_NGAY = 100000;

void NhanVienVanPhong::nhap() {
	NhanVien::nhap();
	do {
		std::cout << "Nhap so ngay lam viec: "; std::cin >> soNgayLamViec;
		if (soNgayLamViec < 0) std::cout << "So ngay lam viec phai lon hon hoac = 0\n";
	} while (soNgayLamViec < 0);

	std::cin.ignore(1000, '\n');
}

void NhanVienVanPhong::xuat() {
	NhanVien::xuat();
	std::cout << "Luong: " << tinhLuong() << std::endl;
}

double NhanVienVanPhong::tinhLuong() {
	return soNgayLamViec * LUONG_NGAY;
}

std::string NhanVienVanPhong::getLoaiNV() {
	return "Nhan vien van phong";
}