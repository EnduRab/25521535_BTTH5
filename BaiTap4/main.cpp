#include "NhanVien.h"
#include "LapTrinhVien.h"
#include "KiemChungVien.h"
#include <iostream>
#include <memory>
#include <iomanip>
#include <vector>

long double timCaoNhat(vector<unique_ptr<NhanVien>>& danhSach, string loai) {
	long double max = -1;
	// Tao bien tam max = -1, neu luong hien tai cao hon max thi gan max = luong hien tai
	if (loai == "ALL") {
		for (auto& nv : danhSach) {
			if (nv->tinhLuong() > max) {
				max = nv->tinhLuong();
			}
		}
	}
	else {
		for (auto& nv : danhSach) {
			if (nv->getLoaiNV() == loai) {
				if (nv->tinhLuong() > max) {
					max = nv->tinhLuong();
				}
			}
		}
	}
	return max;
}

long double timThapNhat(vector<unique_ptr<NhanVien>>& danhSach, string loai) {
	long double min = 1e18;
	// Tao bien tam min = 1e18, neu luong hien tai thap hon min thi gan min = luong hien tai
	if (loai == "ALL") {
		for (auto& nv : danhSach) {
			if (nv->tinhLuong() < min) {
				min = nv->tinhLuong();
			}
		}
	}
	else {
		for (auto& nv : danhSach) {
			if (nv->getLoaiNV() == loai) {
				if (nv->tinhLuong() < min) {
					min = nv->tinhLuong();
				}
			}
		}
	}
	return min;
}

int main() {

	cout << fixed << setprecision(2);

	// Sử dụng unique_ptr để tự động giải phóng bộ nhớ sau khi kết thúc main
	vector<unique_ptr<NhanVien>> danhSach;

	// nhap
	int opt;
	do {
		cout << "NHAP DANH SACH NHAN VIEN\n";
		cout << "1. Nhap lap trinh vien\n";
		cout << "2. Nhap kiem chung vien\n";
		cout << "0. Dung nhap va bat dau xuat\n";
		cout << "-----> Nhap lua chon: ";
		cin >> opt;
		if (opt == 1) {
			auto nv = make_unique<LapTrinhVien>();
			nv->nhap();
			danhSach.push_back(move(nv));
		}
		else if (opt == 2) {
			auto nv = make_unique<KiemChungVien>();
			nv->nhap();
			danhSach.push_back(move(nv));
		}
		else if (opt != 0) {
			cout << "Lua chon khong hop le, vui long nhap lai!\n";
		}
		else {
			cout << "\n---NHAP THANH CONG, BAT DAU XUAT DANH SACH---\n";
			break;
		}
	} while (opt != 0);

	// xuat
	cout << "=== DANH SACH TOAN BO NHAN VIEN ===\n";
	if (danhSach.empty()) {
		cout << "DANH SACH TRONG\n";
	}
	for (int i = 0; i < danhSach.size(); ++i) {
		cout << "--- NHAN VIEN THU " << i + 1 << " ---\n";
		danhSach[i]->xuat();
		cout << "-----------------\n";
	}
	

	// xuat thap hon trung binh
	cout << "\n=== DANH SACH NHAN VIEN LUONG THAP HON TRUNG BINH ===\n";
	if (danhSach.empty()) {
		cout << "DANH SACH TRONG\n";
	}
	else {
		// tinh luong trung binh
		long double average = 0;
		for (auto& nv : danhSach) {
			average += nv->tinhLuong();
		}
		average /= (long double)danhSach.size();
		// xuat
		for (auto& nv : danhSach) {
			if (nv->tinhLuong() < average) {
				nv->xuat();
			}
		}
	}

	
	long double maxNV = timCaoNhat(danhSach, "ALL");
	long double minNV = timThapNhat(danhSach, "ALL");
	long double maxLTV = timCaoNhat(danhSach, "Lap trinh vien");
	long double minKCV = timThapNhat(danhSach, "Kiem chung vien");

	// Xuat nhan vien luong cao nhat
	cout << "\n=== DANH SACH CAC NHAN VIEN LUONG CAO NHAT ===\n";
	if (danhSach.empty()) {
		cout << "DANH SACH TRONG\n";
	}
	for (auto& nv : danhSach) {
		if (nv->tinhLuong() == maxNV) {
			nv->xuat();
		}
	}

	// Xuat nhan vien luong thap nhat
	cout << "\n=== DANH SACH CAC NHAN VIEN LUONG THAP NHAT ===\n";
	if (danhSach.empty()) {
		cout << "DANH SACH TRONG\n";
	}
	for (auto& nv : danhSach) {
		if (nv->tinhLuong() == minNV) {
			nv->xuat();
		}
	}

	bool foundLTV = false;
	bool foundKCV = false;
	for (auto& nv : danhSach) {
		if (nv->getLoaiNV() == "Lap trinh vien") {
			foundLTV = true;
		}
		if (nv->getLoaiNV() == "Kiem chung vien") {
			foundKCV = true;
		}
		if (foundLTV == true && foundKCV == true) break;
	}

	// Xuat lap trinh vien luong cao nhat
	cout << "\n=== DANH SACH CAC LAP TRINH VIEN LUONG CAO NHAT ===\n";
	if (foundLTV == false) {
		cout << "DANH SACH RONG\n";
	}
	for (auto& nv : danhSach) {
		if (nv->tinhLuong() == maxLTV && nv->getLoaiNV() == "Lap trinh vien") {
			nv->xuat();
		}
	}


	// xuat kiem chung vien luong thap nhat
	cout << "\n=== DANH SACH CAC KIEM CHUNG VIEN LUONG THAP NHAT ===\n";
	if (foundKCV == false) {
		cout << "DANH SACH RONG\n";
	}
	for (auto& nv : danhSach) {
		if (nv->tinhLuong() == minKCV && nv->getLoaiNV() == "Kiem chung vien") {
			nv->xuat();
		}
	}
	return 0;
}