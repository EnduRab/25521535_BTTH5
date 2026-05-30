#pragma once

#include "SinhVien.h"
#include <string>

using namespace std;

class SinhVienDaiHoc : public SinhVien {
protected:
	string tenLuanVan;
	double diemLuanVan;
public:
	void nhap() override;
	void xuat() override;
	bool xetTN() override;
	string getLoaiSV() override;
};