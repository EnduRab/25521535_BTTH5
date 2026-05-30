#pragma once

#include <string>

using namespace std;
const double VAT = 0.1;

class KhachHang {
protected:
	string ten;
	double donGiaHang;
	int soLuongHang;
	double tienTra;
public:
	KhachHang();
	virtual ~KhachHang() = default;
	virtual void nhap(ifstream& fin);
	virtual void xuat(ofstream& fout);
	virtual double tinhTienTra() = 0;
	double getTien();
};