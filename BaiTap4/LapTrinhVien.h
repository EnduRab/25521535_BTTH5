#pragma once
#include "NhanVien.h"

const long double LUONG_OVERTIME = 200000;

class LapTrinhVien : public NhanVien {
private:
	int soGioOT;
public:
	void nhap() override;
	void xuat() override;
	long double tinhLuong() override;
	string getLoaiNV() override;
};
