#pragma once

#include "KhachHang.h"

class KhachHangB : public KhachHang {
private:
	double phanTramKhuyenMai;
	int soNamThanThiet;
public:
	void nhap(ifstream& fin) override;
	double tinhTienTra() override;
};