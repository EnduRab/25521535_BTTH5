#pragma once

#include "GiaoDich.h"

enum class LOAI_NHA {
	CAO_CAP,
	THUONG
};

class GDNhaPho : public GiaoDich {
private:
	LOAI_NHA loaiNha;
public:
	void nhap() override;
	void xuat() override;
	long double tinhTien() override;
	LOAI_GIAO_DICH getLoaiGiaoDich() override;
};