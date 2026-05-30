#pragma once

#include "GiaoDich.h"

class GDCanHoChungCu : public GiaoDich {
private:
	int maCan;
	int viTriTang;
public:
	void nhap() override;
	void xuat() override;
	long double tinhTien() override;
	LOAI_GIAO_DICH getLoaiGiaoDich() override;
};