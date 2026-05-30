#include "NhanVienVanPhong.h"
#include "NhanVienSanXuat.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;


int main() {

	cout << fixed << setprecision(2);

	// Sử dụng unique_ptr để tự động giải phóng bộ nhớ sau khi kết thúc main
	vector<unique_ptr<NhanVien>> danhSach;
	// Nhap
	int opt;
	do {
		cout << "1. Nhap nhan vien van phong\n";
		cout << "2. Nhap nhan vien san xuat\n";
		cout << "0. Dung nhap va bat dau xuat\n";
		cout << "---> Nhap lua chon: ";
		cin >> opt;
		cin.ignore(1000, '\n');
		if (opt == 0) {
			break;
		}
		else if (opt == 1) {
			auto nv = make_unique<NhanVienVanPhong>();
			nv->nhap();
			danhSach.push_back(move(nv));
		}
		else if (opt == 2) {
			auto nv = make_unique<NhanVienSanXuat>();
			nv->nhap();
			danhSach.push_back(move(nv));
		}
	} while (opt != 0);

	double tongLuong = 0;
	int idx_tuoi_cao_nhat = 0;
	int idx_luong_thap_nhat = 0;
	double luongMin = 0;
	CDate tuoiCaoNhat;

	// Xuat

	cout << "===== DANH SACH NHAN VIEN TRONG CONG TY =====\n";
	if (danhSach.empty()) {
		cout << "Danh sach nhan vien rong\n";
	}

	bool foundSX = false;
	bool foundVP = false;

	for (int i = 0; i < danhSach.size(); ++i) {
		cout << "\n=== NHAN VIEN THU " << i + 1 << " ===\n";
		danhSach[i]->xuat();
		double luongHienTai = danhSach[i]->tinhLuong();
		tongLuong += luongHienTai;

		// xu ly tim vi tri nhan vien san xuat luong thap nhat trong vector
		if ((i == 0 || luongHienTai < luongMin) && (danhSach[i]->getLoaiNV() == "Nhan vien san xuat")) {
			luongMin = luongHienTai;
			idx_luong_thap_nhat = i;
			foundSX = true;
		}

		CDate ngaySinhHienTai = danhSach[i]->getNgaySinh();
		// xu ly tim vi tri nhan vien van phong tuoi cao nhat trong vector
		if ((i == 0 || tuoiCaoNhat > ngaySinhHienTai) && (danhSach[i]->getLoaiNV() == "Nhan vien van phong")) {
			tuoiCaoNhat = ngaySinhHienTai;
			idx_tuoi_cao_nhat = i;
			foundVP = true;
		}
	}
	cout << "\n=== TONG LUONG CUA CONG TY ===\n" << tongLuong << endl;
	cout << "\n=== NHAN VIEN SAN XUAT CO LUONG THAP NHAT ===\n";
	if (foundSX == false) {
		cout << "KHONG TON TAI NHAN VIEN SAN XUAT TRONG CONG TY\n";
	}
	else danhSach[idx_luong_thap_nhat]->xuat();

	cout << "\n=== NHAN VIEN VAN PHONG CO TUOI CAO NHAT ===\n";
	if (foundVP == false) {
		cout << "KHONG TON TAI NHAN VIEN VAN PHONG TRONG CONG TY\n";
	}
	else danhSach[idx_tuoi_cao_nhat]->xuat();
}