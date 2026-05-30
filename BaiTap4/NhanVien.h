#pragma once

#include <string>

using namespace std;

class NhanVien {
protected:
	int maNhanVien;
	string hoTen;
	int tuoi;
	string soDienThoai;
	string email;
	long double luongCoBan;
public:
	NhanVien();
	virtual ~NhanVien() = default;
	virtual void nhap();
	virtual void xuat();
	virtual long double tinhLuong() = 0;
	virtual string getLoaiNV() = 0;
};