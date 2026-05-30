#pragma once

#include "GiaoDich.h"

class GDDat : public GiaoDich {
private:
	char loaiDat;
public:
	void nhap() override;
	void xuat() override;
	long double tinhTien() override;
	LOAI_GIAO_DICH getLoaiGiaoDich() override;
};