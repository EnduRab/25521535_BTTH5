#include <iostream>
#include "SinhVien.h"

SinhVien::SinhVien() {
	maSoSV = 0;
	tongSoTinChi = 0;
	diemTB = 0;
}

SinhVien::~SinhVien() {}
 
void SinhVien::nhap() {
	cout << "Nhap ma so sinh vien: "; cin >> maSoSV; cin.ignore(1000, '\n');
	cout << "Nhap ho va ten: "; getline(cin, hoTen);
	cout << "Nhap dia chi: "; getline(cin, diaChi);
	cout << "Nhap tong so tin chi: "; cin >> tongSoTinChi;
	cout << "Nhap diem trung binh: "; cin >> diemTB;
}

void SinhVien::xuat() {
	cout << "Loai sinh vien: " << getLoaiSV() << endl;
	cout << "Ma so sinh vien: " << maSoSV << endl;
	cout << "Ho va ten: " << hoTen << endl;
	cout << "Dia chi: " << diaChi << endl;
	cout << "Tong so tin chi: " << tongSoTinChi << endl;
	cout << "Diem trung binh: " << diemTB << endl;
}

double SinhVien::getDTB() {
	return diemTB;
}

 