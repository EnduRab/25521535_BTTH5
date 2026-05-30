#pragma once
#include "NhanVien.h"

const long double DON_GIA_TREN_SO_LOI = 50000;

class KiemChungVien : public NhanVien {
private:
	int soLoiPhatHien;
public:
	void nhap() override;
	void xuat() override;
	long double tinhLuong() override;
	string getLoaiNV() override;
};