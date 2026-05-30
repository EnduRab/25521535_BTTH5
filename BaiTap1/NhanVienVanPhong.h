#pragma once

#include "NhanVien.h"

class NhanVienVanPhong : public NhanVien {
private:
	int soNgayLamViec;
public:
	void nhap() override;
	void xuat() override;
	double tinhLuong() override;
	std::string getLoaiNV() override;
};