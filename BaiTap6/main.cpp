#include "KhachHang.h"
#include "KhachHangA.h"
#include "KhachHangB.h"
#include "KhachHangC.h"
#include <fstream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <memory>

using namespace std;

double tongTienThuDc(vector<unique_ptr<KhachHang>>& danhSach) {
	double sum = 0;
	for (auto& kh : danhSach) {
		sum += kh->getTien();
	}
	return sum;
}

int main() {
	ifstream fin("XYZ.INP");
	ofstream fout("XYZ.OUT");
	fout << fixed << setprecision(2);
	
	vector<unique_ptr<KhachHang>> danhSach;
	int x, y, z;
	fin >> x >> y >> z;

	for (int i = 0; i < x; ++i) {
		auto kh = make_unique<KhachHangA>();
		kh->nhap(fin);
		danhSach.push_back(move(kh));
	}
	for (int i = 0; i < y; ++i) {
		auto kh = make_unique<KhachHangB>();
		kh->nhap(fin);
		danhSach.push_back(move(kh));
	}
	for (int i = 0; i < z; ++i) {
		auto kh = make_unique<KhachHangC>();
		kh->nhap(fin);
		danhSach.push_back(move(kh));
	}
	
	for (auto& kh : danhSach) {
		kh->xuat(fout);
	}
	fout << tongTienThuDc(danhSach) << endl;
	
	fin.close();
	fout.close();
}