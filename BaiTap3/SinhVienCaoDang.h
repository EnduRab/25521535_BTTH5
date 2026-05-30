#pragma once

#include "SinhVien.h"

class SinhVienCaoDang : public SinhVien {
private:
	double diemThiTN;
public:
	void nhap() override;
	void xuat() override;
	bool xetTN() override;
	string getLoaiSV() override;
};