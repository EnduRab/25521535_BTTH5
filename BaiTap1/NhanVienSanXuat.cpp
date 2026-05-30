#include "NhanVienSanXuat.h"
#include <iostream>

const double THUONG_THEO_SAN_PHAM = 5000;

void NhanVienSanXuat::nhap()  {
	NhanVien::nhap();

	do {
		std::cout << "Nhap luong can ban: "; std::cin >> luongCanBan;
		if (luongCanBan < 0) std::cout << "Luong can ban phai lon hon hoac = 0\n";
	} while (luongCanBan < 0);


	do {
		std::cout << "Nhap so san pham: "; std::cin >> soSanPham;
		if (soSanPham < 0) std::cout << "So san pham phai lon hon hoac = 0\n";
	} while (soSanPham < 0);

	std::cin.ignore(1000, '\n');
}

void NhanVienSanXuat::xuat() {
	NhanVien::xuat();
	std::cout << "Luong: " << tinhLuong() << std::endl;
}

double NhanVienSanXuat::tinhLuong() {
	return luongCanBan + soSanPham * THUONG_THEO_SAN_PHAM;
}

std::string NhanVienSanXuat::getLoaiNV() {
	return "Nhan vien san xuat";
}