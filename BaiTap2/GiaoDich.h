#pragma once

#include "CDate.h"

using namespace std;

enum class LOAI_GIAO_DICH {
	DAT,
	NHA_PHO,
	CHUNG_CU
};

class GiaoDich {
protected:
	int maGiaoDich;
	CDate ngayGiaoDich;
	long double donGia;
	double dienTich;
public:
	GiaoDich();
	GiaoDich(int, CDate ,double, double);
	virtual ~GiaoDich();
	virtual void nhap();
	virtual void xuat();
	virtual LOAI_GIAO_DICH getLoaiGiaoDich() = 0;
	virtual long double tinhTien() = 0;

	int getNam();
	int getThang();
};