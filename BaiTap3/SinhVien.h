#pragma once

#include <string>

using namespace std;

class SinhVien {
protected:
	int maSoSV;
	string hoTen;
	string diaChi;
	int tongSoTinChi;
	double diemTB;
public:
	SinhVien();
	SinhVien(int, string, string, int, double);
	virtual ~SinhVien();
	virtual void nhap();
	virtual void xuat();
	virtual bool xetTN() = 0;
	virtual string getLoaiSV() = 0;
	double getDTB();
};