#include "NhanVien.h"
#include <iostream>

void NhanVien::nhap() {
	std::cout << "Nhap ho va ten: "; std::getline(std::cin, hoTen);
	std::cout << "Nhap ngay thang nam sinh\n"; std::cin >> ngaySinh;
}

void NhanVien::xuat() {
	std::cout << "-----------------------------------\n";
	std::cout << "Loai nhan vien: " << getLoaiNV() << std::endl;
	std::cout << "Ho va ten: " << hoTen << std::endl;
	std::cout << "Ngay sinh: " << ngaySinh << std::endl;
}

CDate NhanVien::getNgaySinh() {
	return ngaySinh;
}