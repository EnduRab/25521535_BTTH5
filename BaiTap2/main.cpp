#include "GiaoDich.h"
#include "GDDat.h"
#include "GDNhaPho.h"
#include "GDCanHoChungCu.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>

using namespace std;

int demSL_tungLoai_GiaoDich(vector<unique_ptr<GiaoDich>>& danhSach, LOAI_GIAO_DICH a) {
	int count = 0;
	for (int i = 0; i < danhSach.size(); ++i) {
		if (danhSach[i]->getLoaiGiaoDich() == a) {
			count++;
		}
	}
	return count;
}

long double trungBinhThanhTienChungCu(vector<unique_ptr<GiaoDich>>& danhSach, int count) {
	if (count == 0) return 0;
	long double average = 0;
	for (auto& gd : danhSach) {
		if (gd->getLoaiGiaoDich() == LOAI_GIAO_DICH::CHUNG_CU) {
			average += gd->tinhTien();
		}
	}
	return average / (long double)count;
}

long double timCaoNhatNhaPho(vector<unique_ptr<GiaoDich>>& danhSach) {
	long double max = 0;
	for (auto& gd : danhSach) {
		if (gd->tinhTien() > max && gd->getLoaiGiaoDich() == LOAI_GIAO_DICH::NHA_PHO) {
			max = gd->tinhTien();
		}
	}
	return max;
}


int main() {

	cout << fixed << setprecision(2);

	vector<unique_ptr<GiaoDich>> danhSach;
	// Nhap danh sach
	int opt;
	do {
		cout << "--- NHAP LOAI GIAO DICH ---\n";
		cout << "1. DAT\n";
		cout << "2. NHA PHO\n";
		cout << "3. CAN HO CHUNG CU\n";
		cout << "0. DUNG NHAP VA BAT DAU XUAT\n";
		cout << "---> NHAP LUA CHON: "; cin >> opt;
		if (opt == 1) {
			auto gd = make_unique<GDDat>();
			gd->nhap();
			danhSach.push_back(move(gd));
		}
		else if (opt == 2) {
			auto gd = make_unique<GDNhaPho>();
			gd->nhap();
			danhSach.push_back(move(gd));
		}
		else if (opt == 3) {
			auto gd = make_unique<GDCanHoChungCu>();
			gd->nhap();
			danhSach.push_back(move(gd));
		}
		else if (opt != 0) {
			cout << "LUA CHON KHONG HOP LE, VUI LONG NHAP LAI\n";
		}
		else {
			cout << "\nNHAP THANH CONG, BAT DAU XUAT\n";
		}
	} while (opt != 0);

	cout << "\n===== DANH SACH CAC GIAO DICH =====\n";
	
	if (danhSach.empty()) {
		cout << "KHONG CO GIAO DICH DE XUAT\n";
	}
	else {
		for (int i = 0; i < danhSach.size(); ++i) {
			cout << "\n-----------------------\n";
			cout << "--- GIAO DICH THU " << i + 1 << " ---\n";
			danhSach[i]->xuat();
			cout << "-----------------------\n";
		}
	}

	int countDat = demSL_tungLoai_GiaoDich(danhSach, LOAI_GIAO_DICH::DAT);
	int countNhaPho = demSL_tungLoai_GiaoDich(danhSach, LOAI_GIAO_DICH::NHA_PHO);
	int countCC = demSL_tungLoai_GiaoDich(danhSach, LOAI_GIAO_DICH::CHUNG_CU);

	cout << "\n---> SO LUONG GIAO DICH DAT: " << countDat << endl;
	cout << "---> SO LUONG GIAO DICH NHA PHO: " << countNhaPho << endl;
	cout << "---> SO LUONG GIAO DICH CAN HO CHUNG CU: " << countCC << endl;


	cout << "\n ======> TRUNG BINH THANH TIEN CUA GIAO DICH CAN HO CHUNG CU: " << trungBinhThanhTienChungCu(danhSach, countCC) << endl;

	long double max = timCaoNhatNhaPho(danhSach);
	cout << "\n=== DANH SACH NHA PHO CO TRI GIA CAO NHAT ===\n";
	if (countNhaPho == 0) {
		cout << "KHONG CO GIAO DICH DE XUAT\n";
	}
	else {
		for (int i = 0; i < danhSach.size(); ++i) {
			if (danhSach[i]->tinhTien() == max && danhSach[i]->getLoaiGiaoDich() == LOAI_GIAO_DICH::NHA_PHO) {
				cout << "\n-----------------------\n";
				cout << "--- GIAO DICH THU " << i + 1 << " ---\n";
				danhSach[i]->xuat();
				cout << "-----------------------\n";
			}
		}
	}
	
	bool found = false;
	cout << "\n=== DANH SACH GIAO DICH TRONG THANG 12 NAM 2024 ===\n";
	for (int i = 0; i < danhSach.size(); ++i) {
		if (danhSach[i]->getThang() == 12 && danhSach[i]->getNam() == 2024) {
			found = true;
			cout << "\n-----------------------\n";
			cout << "--- GIAO DICH THU " << i + 1 << " ---\n";
			danhSach[i]->xuat();
			cout << "-----------------------\n";
		}
	}
	if (found == false) cout << "KHONG CO GIAO DICH DE XUAT\n";

	return 0;
}
