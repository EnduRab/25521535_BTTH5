#pragma once

#include <string>
#include "CDate.h"

class NhanVien {
protected:
	std::string hoTen;
	CDate ngaySinh;
	double luong;
public:
	virtual void nhap();
	virtual void xuat();
	virtual double tinhLuong() = 0;
	virtual std::string getLoaiNV() = 0;

	CDate getNgaySinh();
};