#include "GiaoDich.h"
#include <iostream>
#include <string>

using namespace std;

string xuat_loai(LOAI_GIAO_DICH loai) {
	switch (loai) {
	case LOAI_GIAO_DICH::DAT:
		return "Dat";
	case LOAI_GIAO_DICH::NHA_PHO:
		return "Nha Pho";
	case LOAI_GIAO_DICH::CHUNG_CU:
		return "Chung Cu";
	default:
		return "Khong xac dinh";
	}
}

GiaoDich::~GiaoDich() {}

GiaoDich::GiaoDich() {
	maGiaoDich = 0;
	donGia = 0;
	dienTich = 0;
}

GiaoDich::GiaoDich(int ma, CDate ngay, double dg, double dt) {
	maGiaoDich = ma;
	ngayGiaoDich = ngay;
	donGia = dg;
	dienTich = dt;
}

void GiaoDich::nhap() {
	cout << "Nhap ma giao dich: "; cin >> maGiaoDich;
	cout << "Nhap ngay/thang/nam\n"; cin >> ngayGiaoDich;
	cout << "Nhap don gia: "; cin >> donGia;
	cout << "Nhap dien tich: "; cin >> dienTich;
}

void GiaoDich::xuat() {
	cout << "-----------------------\n";
	cout << "Loai giao dich: " << xuat_loai(getLoaiGiaoDich()) << endl;
	cout << "Ma giao dich: " << maGiaoDich << endl;
	cout << "Ngay giao dich: " << ngayGiaoDich << endl;
	cout << "Dien tich: " << dienTich << endl;
}

int GiaoDich::getNam() {
	return ngayGiaoDich.getNam();
}

int GiaoDich::getThang() {
	return ngayGiaoDich.getThang();
}
