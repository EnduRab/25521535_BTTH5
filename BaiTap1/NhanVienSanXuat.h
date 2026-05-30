#pragma once

#include "NhanVien.h"

class NhanVienSanXuat : public NhanVien {
private:
	double luongCanBan;
	int soSanPham;
public:
	void nhap() override;
	void xuat() override;
	double tinhLuong() override;
	std::string getLoaiNV() override;
};