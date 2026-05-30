#include "SinhVien.h"
#include "SinhVienCaoDang.h"
#include "SinhVienDaiHoc.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

double svDiemCaoNhat(vector<unique_ptr<SinhVien>>& danhSach, string loai) {
	double max = 0;
	for (auto& sv : danhSach) {
		if (sv->getLoaiSV() == loai && sv->getDTB() > max) {
			max = sv->getDTB();
		}
	}
	return max;
}

int demKoDuTN(vector<unique_ptr<SinhVien>>& danhSach, string loai) {
	int count = 0;
	for (auto& sv : danhSach) {
		if (sv->getLoaiSV() == loai && sv->xetTN() == 0) {
			count++;
		}
	}
	return count;
}

int main() {
	vector<unique_ptr<SinhVien>> danhSach;

	// nhap
	int opt;
	do {
		cout << "NHAP DANH SACH SINH VIEN\n";
		cout << "1. Nhap sinh vien cao dang\n";
		cout << "2. Nhap sinh vien dai hoc\n";
		cout << "0. Dung nhap va bat dau xuat\n";
		cout << "-----> Nhap lua chon: ";
		cin >> opt;
		if (opt == 1) {
			auto sv = make_unique<SinhVienCaoDang>();
			sv->nhap();
			danhSach.push_back(move(sv));
		}
		else if (opt == 2) {
			auto sv = make_unique<SinhVienDaiHoc>();
			sv->nhap();
			danhSach.push_back(move(sv));
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
	cout << "\n=== DANH SACH CAC SINH VIEN ===\n";
	if (danhSach.empty()) {
		cout << "DANH SACH RONG\n";
	}
	else {
		for (int i = 0; i < danhSach.size(); ++i) {
			cout << "- SINH VIEN THU " << i + 1 << " -\n";
			danhSach[i]->xuat();
			cout << "-------------\n";
		}
	}


	cout << "=== DANH SACH CAC SINH VIEN KHONG DU DIEU KIEN TOT NGHIEP ===\n";
	bool found = false;
		for (int i = 0; i < danhSach.size(); ++i) {
			if (danhSach[i]->xetTN() == 0) {
				found = true;
				cout << "- SINH VIEN THU " << i + 1 << " -\n";
				danhSach[i]->xuat();
				cout << "-------------\n";
			}
		}
		if (found == false) cout << "DANH SACH RONG\n";


	double daihocCaoNhat = svDiemCaoNhat(danhSach, "Dai hoc");
	double caodangCaoNhat = svDiemCaoNhat(danhSach, "Cao dang");
	cout << "=== DANH SACH CAC SINH VIEN DAI HOC CO DIEM TRUNG BINH CAO NHAT ===\n";
	bool foundDH = false;

		for (int i = 0; i < danhSach.size(); ++i) {
			if (danhSach[i]->getLoaiSV() == "Dai hoc" && danhSach[i]->getDTB() == daihocCaoNhat) {
				foundDH = true;
				cout << "- SINH VIEN THU " << i + 1 << " -\n";
				danhSach[i]->xuat();
				cout << "-------------\n";
			}
		}
		if(foundDH == false) cout << "DANH SACH RONG\n";

	cout << "=== DANH SACH CAC SINH VIEN CAO DANG CO DIEM TRUNG BINH CAO NHAT ===\n";
	bool foundCD = false;

		for (int i = 0; i < danhSach.size(); ++i) {
			if (danhSach[i]->getLoaiSV() == "Cao dang" && danhSach[i]->getDTB() == caodangCaoNhat) {
				foundCD = true;
				cout << "- SINH VIEN THU " << i + 1 << " -\n";
				danhSach[i]->xuat();
				cout << "-------------\n";
			}
		}
		if (foundCD == false) cout << "DANH SACH RONG\n";


	cout << "----> SO LUONG SINH VIEN CAO DANG KHONG DU DIEU KIEN TOT NGHIEP: " << demKoDuTN(danhSach, "Cao dang") << endl;
	cout << "----> SO LUONG SINH VIEN DAI HOC KHONG DU DIEU KIEN TOT NGHIEP: " << demKoDuTN(danhSach, "Dai hoc") << endl;
}