#include "CDate.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int ngayTrongThang(int thang,int nam) {
	int ngay[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	// neu nam nhuan thi thang 2 co 29 ngay
	if (((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0))) {
		ngay[2] = 29;
	}
	return ngay[thang];
}

bool ngayHopLe(int ngay, int thang, int nam) {
	if (ngay <= 0 || thang <= 0 || nam <= 0 || thang > 12 || ngay > ngayTrongThang(thang, nam)) return false;
	return true;
}

CDate::CDate(int ng,int th,int n): ngay(ng),thang(th),nam(n) {}

istream& operator>>(istream& in, CDate& date) {
	do {
		cout << "Nhap ngay: "; in >> date.ngay;
		cout << "Nhap thang: "; in >> date.thang;
		cout << "Nhap nam: "; in >> date.nam;
		if (!ngayHopLe(date.ngay, date.thang, date.nam))
			cout << "Ngay thang nam khong hop le, vui long nhap lai\n";
	} while (!ngayHopLe(date.ngay,date.thang,date.nam));
	return in;
}

ostream& operator<<(ostream& out, const CDate& date) {
	string dateStr = "";
	if (date.ngay < 10) dateStr += "0";
	dateStr += to_string(date.ngay) + "/";
	if (date.thang < 10) dateStr += "0";
	dateStr += to_string(date.thang) + "/";
	dateStr += to_string(date.nam);
	out << dateStr;
	return out;
}

int CDate::getNam() {
	return nam;
}

int CDate::getThang() {
	return thang;
}