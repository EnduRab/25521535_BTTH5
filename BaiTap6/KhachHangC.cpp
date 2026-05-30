#include "KhachHangC.h"

double KhachHangC::tinhTienTra() {
	tienTra = (soLuongHang * donGiaHang) * 0.5;
	tienTra *= (1 + VAT);
	return tienTra;
}